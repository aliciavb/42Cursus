/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:37:23 by avinals-          #+#    #+#             */
/*   Updated: 2025/08/21 13:45:31 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_if_digit(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
			{
				printf("Error: '%s' is not a valid number.\n", av[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_philo_range(char **av)
{
	int	philo_num;

	philo_num = ft_atoi(av[1]);
	if (philo_num < 1 || philo_num > 200)
	{
		printf("Error: philo_num must be between 1 and 200.\n");
		return (1);
	}
	return (0);
}

static int	check_times(char **av)
{
	int	i;
	int	time;

	i = 2;
	while (i < 5)
	{
		time = ft_atoi(av[i]);
		if (time <= 0)
		{
			printf("Error: '%s' must be greater than 0.\n", av[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	validate_arguments(int ac, char **av)
{
	if (check_if_digit(av, ac))
		return (1);
	if (check_philo_range(av))
		return (1);
	if (check_times(av))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Error: Incorrect number of arguments.\n");
		printf("Try: ./philo number_of_philosophers time_to_die "
			"time_to_eat time_to_sleep [times_must_eat]\n");
		return (1);
	}
	if (validate_arguments(ac, av))
		return (1);
	if (init_data(&data, av))
		return (1);
	if (init_philosophers(&data))
	{
		cleanup_all(&data);
		return (1);
	}
	if (start_simulation(&data))
	{
		cleanup_all(&data);
		return (1);
	}
	cleanup_all(&data);
	return (0);
}
