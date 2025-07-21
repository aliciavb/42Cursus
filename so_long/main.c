/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:26:33 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/17 22:36:10 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(const char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	char	**map;
	int		i;

	if (ac != 2)
		exit_error("Error. Try: ./so_long <maps/example.ber>\n");
	map = load_map(av[1]);
	if (!map_is_valid(map))
		exit_error("Invalid map.\n");
	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}
