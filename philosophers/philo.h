/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:37:46 by avinals           #+#    #+#             */
/*   Updated: 2025/08/10 14:51:18 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>

typedef struct s_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*forks_mutex;
	pthread_t		*philosophers_threads;
	int				*philosophers_status;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			time_to_die;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex;
}	t_philo;

int is_digit(char c);
int ft_atoi(const char *str);

#endif