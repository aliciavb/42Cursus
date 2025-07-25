/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:00:00 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/25 14:51:41 by avinals          ###   ########.fr       */
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

static void	load_basic_images(t_game *game, int *width, int *height)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			WALL_SPRITE, width, height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			FLOOR_SPRITE, width, height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			COLLECT_SPRITE, width, height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			EXIT_SPRITE, width, height);
}

static void	load_player_images(t_game *game, int *width, int *height)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			PLAYER_SPRITE, width, height);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			PLAYER_RIGHT, width, height);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			PLAYER_LEFT, width, height);
}

static void	load_enemy_images(t_game *game, int *width, int *height)
{
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			ENEMY_SPRITE, width, height);
	game->img_enemy_frames[0] = mlx_xpm_file_to_image(game->mlx,
			ENEMY_FRAME1, width, height);
	game->img_enemy_frames[1] = mlx_xpm_file_to_image(game->mlx,
			ENEMY_FRAME2, width, height);
	game->img_enemy_frames[2] = mlx_xpm_file_to_image(game->mlx,
			ENEMY_FRAME3, width, height);
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	load_basic_images(game, &width, &height);
	load_player_images(game, &width, &height);
	load_enemy_images(game, &width, &height);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_player_right || !game->img_player_left
		|| !game->img_collectible || !game->img_exit || !game->img_enemy
		|| !game->img_enemy_frames[0] || !game->img_enemy_frames[1]
		|| !game->img_enemy_frames[2])
		exit_error("Error creating images\n");
}
