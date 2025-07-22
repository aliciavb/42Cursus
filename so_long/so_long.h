/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:06:23 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/22 22:31:50 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

// sprites in 64x64
# define TILE_SIZE 64

// key codes in linux to use wasd and arrows
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// assets routes
# define WALL_SPRITE "./textures/wall.xpm"
# define FLOOR_SPRITE "./textures/floor.xpm"
# define PLAYER_SPRITE "./textures/player.xpm"
# define COLLECT_SPRITE "./textures/collectible.xpm"
# define EXIT_SPRITE "./textures/exit.xpm"

typedef struct s_counts
{
	int	player;
	int	exit;
	int	collect;
}	t_counts;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	int		total_collectibles;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
}	t_game;

// main.c
void	exit_error(const char *msg);

// map_init.c
char	**load_map(const char *filepath);
char	**list_to_map(t_list *lines);
t_list	*read_map_lines(const char *filepath);

// map_checks.c
int		map_is_valid(char **map);

// map_utils.c
void	count_map_elements(char **map, t_counts *count);
void	check_walls(char **map);
char	**copy_map(char **map);
void	free_map_copy(char **map);

// game.c
int		init_game(t_game *game, char **map);
void	*create_colored_image(t_game *game, int color);
void	load_images(t_game *game);
void	render_map(t_game *game);
void	cleanup_game(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);

#endif
