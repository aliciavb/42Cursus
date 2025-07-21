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

int init_game(t_game *game, char **map)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);
    game->height = 0;
    while (map[game->height])
        game->height++;
    game->width = ft_strlen(map[0]) - 1;
    game->window = mlx_new_window(game->mlx, game->width * 64,
		game->height * 64, "so_long");
    if (!game->window)
        return (0);
    game->map = map;
    game->moves = 0;
    return (1);
}
