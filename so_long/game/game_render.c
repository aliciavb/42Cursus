/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:00:00 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/25 00:58:31 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*create_colored_image(t_game *game, int color)
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!img)
		return (NULL);
	data = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	fill_image_with_color(data, color, bits_per_pixel, line_length);
	return (img);
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			WALL_SPRITE, &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			FLOOR_SPRITE, &width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			PLAYER_SPRITE, &width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			COLLECT_SPRITE, &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			EXIT_SPRITE, &width, &height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			ENEMY_SPRITE, &width, &height);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collectible || !game->img_exit || !game->img_enemy)
		exit_error("Error creating images\n");
}

void	render_tile(t_game *game, int x, int y, char tile)
{
	void	*img;

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
	else if (tile == 'X')
		img = game->img_enemy;
	else
		img = game->img_floor;
	mlx_put_image_to_window(game->mlx,
		game->window, img, x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_single_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (x == game->player_x && y == game->player_y)
		render_tile(game, x, y, 'P');
	else
	{
		if (game->map[y][x] != '0')
			render_tile(game, x, y, game->map[y][x]);
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_single_tile(game, x, y);
			x++;
		}
		y++;
	}
}
