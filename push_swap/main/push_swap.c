/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:58:48 by avinals           #+#    #+#             */
/*   Updated: 2025/04/07 14:33:41 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	handle_input(int ac, char **av, t_stack_node **a,
	char ***split_args)
{
	if (ac == 2)
	{
		*split_args = split(av[1], ' ');
		if (!*split_args)
			return (1);
		init_stack_a(a, *split_args);
	}
	else
		init_stack_a(a, av + 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_args;

	a = NULL;
	b = NULL;
	split_args = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (handle_input(ac, av, &a, &split_args))
		return (1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	if (split_args)
		free_split(split_args);
	return (0);
}
