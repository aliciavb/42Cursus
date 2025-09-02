/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:37:42 by avinals-          #+#    #+#             */
/*   Updated: 2025/09/02 14:54:23 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_run(char **av)
{
	t_data	data;

	data.philosophers = NULL;
	data.philosophers_threads = NULL;
	data.forks_mutex = NULL;
	init_data_values(&data, av);
	if (init_data_resources(&data))
		return (1);
	if (setup_philosophers_and_forks(&data))
	{
		printf("Error: Failed to initialize philosophers.\n");
		destroy_data_resources(&data);
		return (1);
	}
	if (start_simulation(&data))
	{
		printf("Error: Failed to start simulation.\n");
		cleanup_all(&data);
		return (1);
	}
	print_final_stats(&data); /**********para debug, comentar**********/
	cleanup_all(&data);
	return (0);
}

int	main(int ac, char **av)
{
	if (check_args(ac, av))
		return (1);
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (0);
	return (philo_run(av));
}
