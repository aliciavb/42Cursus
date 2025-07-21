/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:47:41 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/15 19:51:13 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void find_player_position(t_game *game)
{
	int i, j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				game->map[i][j] = '0'; // Convertir posición inicial en suelo
				return;
			}
			j++;
		}
		i++;
	}
}

static void count_collectibles(t_game *game)
{
	int i, j;

	game->total_collectibles = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'C')
				game->total_collectibles++;
			j++;
		}
		i++;
	}
	game->collectibles = 0;
}

void *create_colored_image(t_game *game, int color)
{
	void *img;
	char *data;
	int bits_per_pixel, line_length, endian;
	int x, y;

	img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!img)
		return (NULL);
	data = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			*(unsigned int *)(data + (y * line_length + x * (bits_per_pixel / 8))) = color;
			x++;
		}
		y++;
	}
	return (img);
}

void load_images(t_game *game)
{
	int width, height;

	// Intentar cargar sprites XPM primero
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE, &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE, &width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER_SPRITE, &width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, COLLECT_SPRITE, &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT_SPRITE, &width, &height);

	// Si falló cargar algún sprite, usar colores sólidos como fallback
	if (!game->img_wall)
		game->img_wall = create_colored_image(game, COLOR_WALL);
	if (!game->img_floor)
		game->img_floor = create_colored_image(game, COLOR_FLOOR);
	if (!game->img_player)
		game->img_player = create_colored_image(game, COLOR_PLAYER);
	if (!game->img_collectible)
		game->img_collectible = create_colored_image(game, COLOR_COLLECT);
	if (!game->img_exit)
		game->img_exit = create_colored_image(game, COLOR_EXIT);

	if (!game->img_wall || !game->img_floor || !game->img_player ||
		!game->img_collectible || !game->img_exit)
		exit_error("Error creating images\n");
}
void render_tile(t_game *game, int x, int y, char tile)
{
	void *img;

	if (tile == '1')
		img = game->img_wall;
	else if (tile == '0')
		img = game->img_floor;
	else if (tile == 'P')
		img = game->img_player;
	else if (tile == 'C')
		img = game->img_collectible;
	else if (tile == 'E')
		img = game->img_exit;
	else
		img = game->img_floor;

	mlx_put_image_to_window(game->mlx, game->window, img, x * TILE_SIZE, y * TILE_SIZE);
}

void render_map(t_game *game)
{
	int x, y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			// Primero dibujamos el suelo
			mlx_put_image_to_window(game->mlx, game->window, game->img_floor,
									x * TILE_SIZE, y * TILE_SIZE);

			// Si es la posición del jugador, dibujamos al jugador
			if (x == game->player_x && y == game->player_y)
			{
				render_tile(game, x, y, 'P');
			}
			else
			{
				// Si no es el jugador, dibujamos el tile del mapa (excepto si es suelo)
				if (game->map[y][x] != '0')
					render_tile(game, x, y, game->map[y][x]);
			}
			x++;
		}
		y++;
	}
}

int can_move_to(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

void collect_item(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collectibles++;
		ft_printf("Collectibles: %d/%d\n", game->collectibles, game->total_collectibles);
	}
}

int check_win_condition(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'E' &&
		game->collectibles >= game->total_collectibles)
	{
		ft_printf("¡Felicidades! ¡Has ganado en %d movimientos!\n", game->moves);
		cleanup_game(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void move_player(t_game *game, int new_x, int new_y)
{
	if (!can_move_to(game, new_x, new_y))
		return;

	// Incrementar contador de movimientos
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);

	// Recoger coleccionable si hay uno
	collect_item(game, new_x, new_y);

	// Mover jugador
	game->player_x = new_x;
	game->player_y = new_y;

	// Redibujar mapa
	render_map(game);

	// Verificar condición de victoria
	check_win_condition(game);
}

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		cleanup_game(game);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, game->player_x + 1, game->player_y);

	return (0);
}

int handle_close(t_game *game)
{
	cleanup_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void cleanup_game(t_game *game)
{
	int i;

	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	// Liberar memoria del mapa
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

int init_game(t_game *game, char **map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);

	game->map = map;
	game->height = 0;
	while (map[game->height])
		game->height++;
	game->width = ft_strlen(map[0]);
	if (map[0][game->width - 1] == '\n')
		game->width--;

	game->window = mlx_new_window(game->mlx, game->width * TILE_SIZE,
								  game->height * TILE_SIZE, "so_long");
	if (!game->window)
		return (0);

	game->moves = 0;
	find_player_position(game);
	count_collectibles(game);
	load_images(game);

	// Configurar eventos
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, 17, 0, handle_close, game);

	// Renderizar mapa inicial
	render_map(game);

	return (1);
}
