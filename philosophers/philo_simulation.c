/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:38:41 by avinals-          #+#    #+#             */
/*   Updated: 2025/08/21 13:29:15 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		if (philo->data->num_philosophers == 1)
		{
			ft_usleep(philo->data->time_to_die + 1);
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		if (philo->data->num_philosophers == 1)
		{
			ft_usleep(philo->data->time_to_die + 1);
			pthread_mutex_unlock(philo->left_fork);
			return ;
		}
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
}

static void	eat(t_philo *philo)
{
	take_forks(philo);
	if (philo->data->num_philosophers == 1)
		return ;
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	print_status(philo, "is thinking");
}

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

int	check_death(t_data *data)
{
	int		i;
	long	current_time;

	i = 0;
	while (i < data->num_philosophers)
	{
		current_time = get_time();
		pthread_mutex_lock(&data->philosophers[i].meal_mutex);
		if (current_time - data->philosophers[i].last_meal_time > data->time_to_die)
		{
			pthread_mutex_unlock(&data->philosophers[i].meal_mutex);
			pthread_mutex_lock(&data->death_mutex);
			data->simulation_running = 0;
			pthread_mutex_unlock(&data->death_mutex);
			pthread_mutex_lock(&data->write_mutex);
			printf("%ld %d died\n", current_time - data->start_time, data->philosophers[i].id);
			pthread_mutex_unlock(&data->write_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->philosophers[i].meal_mutex);
		i++;
	}
	return (0);
}

int	all_philosophers_ate(t_data *data)
{
	int	i;
	int	finished_eating;

	if (data->times_must_eat == -1)
		return (0);
	finished_eating = 0;
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_lock(&data->philosophers[i].meal_mutex);
		if (data->philosophers[i].meals_eaten >= data->times_must_eat)
			finished_eating++;
		pthread_mutex_unlock(&data->philosophers[i].meal_mutex);
		i++;
	}
	if (finished_eating == data->num_philosophers)
	{
		pthread_mutex_lock(&data->death_mutex);
		data->simulation_running = 0;
		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_death(data) || all_philosophers_ate(data))
			break ;
		ft_usleep(1);
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
