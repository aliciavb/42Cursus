/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:38:41 by avinals-          #+#    #+#             */
/*   Updated: 2025/08/21 13:46:05 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (!philo->data->simulation_running)
		{
			pthread_mutex_unlock(&philo->data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		eat(philo);
		if (philo->data->num_philosophers == 1)
			break ;
		sleep_and_think(philo);
	}
	return (NULL);
}

int	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		if (pthread_create(&data->philosophers_threads[i], NULL,
				philosopher_routine, &data->philosophers[i]))
			return (1);
		i++;
	}
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine, data))
		return (1);
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(data->philosophers_threads[i], NULL);
		i++;
	}
	pthread_join(data->monitor_thread, NULL);
	return (0);
}
