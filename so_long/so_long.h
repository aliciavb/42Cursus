/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:06:23 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/17 22:31:50 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_counts
{
    int	player;
    int	exit;
    int	collect;
}	t_counts;

typedef struct s_game {
    void    *mlx;
    void    *window;
    char    **map;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     moves;
    int     collectibles;
    void    *img_wall;
    void    *img_floor;
    void    *img_player;
    void    *img_collectible;
    void    *img_exit;
} t_game;

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

#endif

