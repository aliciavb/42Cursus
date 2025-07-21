/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:52:58 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/17 22:35:04 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_player(char **map, int *x, int *y)
{
    int	i;
    int	j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] && map[i][j] != '\n')
        {
            if (map[i][j] == 'P')
            {
                *x = j;
                *y = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

static void	flood_fill_rec(char **map, int x, int y, int *c, int *e)
{
    int	width;
    int	height;

    height = 0;
    while (map[height])
        height++;
    width = ft_strlen(map[0]);
    if (map[0][width - 1] == '\n')
        width--;
    if (x < 0 || y < 0 || x >= width || y >= height)
        return ;
    if (map[y][x] == '1' || map[y][x] == 'F')
        return ;
    if (map[y][x] == 'C')
        (*c)++;
    if (map[y][x] == 'E')
        (*e)++;
    map[y][x] = 'F';
    flood_fill_rec(map, x - 1, y, c, e);
    flood_fill_rec(map, x + 1, y, c, e);
    flood_fill_rec(map, x, y - 1, c, e);
    flood_fill_rec(map, x, y + 1, c, e);
}

static int	flood_fill_check(char **map, int total_collectibles)
{
    char	**map_copy;
    int		player_x;
    int		player_y;
    int		found_c;
    int		found_e;

    map_copy = copy_map(map);
    found_c = 0;
    found_e = 0;
    find_player(map_copy, &player_x, &player_y);
    flood_fill_rec(map_copy, player_x, player_y, &found_c, &found_e);
    free_map_copy(map_copy);
    if (found_c != total_collectibles)
        exit_error("Not all collectibles are reachable\n");
    if (found_e == 0)
        exit_error("Exit is not reachable\n");
    return (1);
}

int	map_is_valid(char **map)
{
    t_counts	count;

    count.player = 0;
    count.exit = 0;
    count.collect = 0;
    count_map_elements(map, &count);
    if (count.player != 1)
        exit_error("It must be exactly one Player\n");
    if (count.exit < 1)
        exit_error("It must be at least one Exit\n");
    if (count.collect < 1)
        exit_error("It must be at least one Collectible\n");
    check_walls(map);
    flood_fill_check(map, count.collect);
    return (1);
}
