/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:37:46 by avinals-          #+#    #+#             */
/*   Updated: 2025/08/21 13:50:18 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **av)
{
	data->num_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->times_must_eat = -1;
	if (av[5])
		data->times_must_eat = ft_atoi(av[5]);
	data->simulation_running = 1;
	data->start_time = get_time();
	if (pthread_mutex_init(&data->write_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&data->death_mutex, NULL))
	{
		pthread_mutex_destroy(&data->write_mutex);
		return (1);
	}
	data->forks_mutex = malloc(sizeof(pthread_mutex_t)
			* data->num_philosophers);
	if (!data->forks_mutex)
	{
		pthread_mutex_destroy(&data->write_mutex);
		pthread_mutex_destroy(&data->death_mutex);
		return (1);
	}
	return (0);
}

int	init_philosophers(t_data *data)
{
	return (setup_philosophers_and_forks(data));
}
