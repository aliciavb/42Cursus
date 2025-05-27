/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:45:34 by avinals           #+#    #+#             */
/*   Updated: 2025/05/27 16:35:18 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_node *stack)
{
	t_node	*outer;
	t_node	*inner;

	outer = stack;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (inner->value == outer->value)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}
