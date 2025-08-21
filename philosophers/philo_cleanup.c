/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:41:31 by avinals-          #+#    #+#             */
/*   Updated: 2025/08/21 13:51:02 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup_philosophers(t_data *data)
{
	int	i;

	if (data->philosophers)
	{
		i = 0;
		while (i < data->num_philosophers)
		{
			pthread_mutex_destroy(&data->philosophers[i].meal_mutex);
			i++;
		}
		free(data->philosophers);
	}
}

static void	cleanup_forks(t_data *data)
{
	int	i;

	if (data->forks_mutex)
	{
		i = 0;
		while (i < data->num_philosophers)
		{
			pthread_mutex_destroy(&data->forks_mutex[i]);
			i++;
		}
		free(data->forks_mutex);
	}
}

void	cleanup_all(t_data *data)
{
	cleanup_philosophers(data);
	if (data->philosophers_threads)
		free(data->philosophers_threads);
	cleanup_forks(data);
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}
