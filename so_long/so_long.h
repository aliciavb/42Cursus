/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:06:23 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/25 00:01:02 by avinals          ###   ########.fr       */
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

# define TILE_SIZE 64

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

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

typedef struct s_flood_data
{
	int	width;
	int	height;
	int	found_c;
	int	found_e;
}	t_flood_data;

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
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
}	t_game;

void	exit_error(char *message);
char	**load_map(const char *filepath);
char	**list_to_map(t_list *lines);
t_list	*read_map_lines(const char *filepath);
int		map_is_valid(char **map);
void	count_map_elements(char **map, t_counts *count);
void	check_walls(char **map);
char	**copy_map(char **map);
void	free_map_copy(char **map);
void	run_game(t_game *game);
int		expose_hook(t_game *game);
void	init_game(t_game *game, char **map);
void	*create_colored_image(t_game *game, int color);
void	load_images(t_game *game);
void	render_tile(t_game *game, int x, int y, char tile);
void	render_map(t_game *game);
void	fill_image_with_color(char *data, int color, int bpp, int line_len);
int		close_window(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		handle_keypress(int key, t_game *game);
void	exit_game(t_game *game);
void	cleanup_game(t_game *game);
void	cleanup_images(t_game *game);

#endif
