/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:37:46 by avinals-          #+#    #+#             */
/*   Updated: 2025/08/21 13:28:51 by avinals-         ###   ########.fr       */
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
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	if (!data->forks_mutex)
	{
		pthread_mutex_destroy(&data->write_mutex);
		pthread_mutex_destroy(&data->death_mutex);
		return (1);
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		if (pthread_mutex_init(&data->forks_mutex[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks_mutex[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_philosophers(t_data *data)
{
	int	i;

	data->philosophers = malloc(sizeof(t_philo) * data->num_philosophers);
	if (!data->philosophers)
		return (1);
	data->philosophers_threads = malloc(sizeof(pthread_t) * data->num_philosophers);
	if (!data->philosophers_threads)
	{
		free(data->philosophers);
		return (1);
	}
	if (init_forks(data))
	{
		free(data->philosophers);
		free(data->philosophers_threads);
		return (1);
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].last_meal_time = data->start_time;
		data->philosophers[i].left_fork = &data->forks_mutex[i];
		data->philosophers[i].right_fork = &data->forks_mutex[(i + 1) % data->num_philosophers];
		data->philosophers[i].data = data;
		if (pthread_mutex_init(&data->philosophers[i].meal_mutex, NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->philosophers[i].meal_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

void	cleanup_all(t_data *data)
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
	if (data->philosophers_threads)
		free(data->philosophers_threads);
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
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}
