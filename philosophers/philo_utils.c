/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:47:35 by avinals           #+#    #+#             */
/*   Updated: 2025/08/10 14:48:50 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' ||
					*str == '\r' || *str == '\v' || *str == '\f'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && is_digit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
