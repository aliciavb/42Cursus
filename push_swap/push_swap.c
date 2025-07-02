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

int main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	printf("DEBUG: ac = %d\n", ac);
	printf("DEBUG: av[1] = '%s'\n", av[1]);
	printf("DEBUG: av[1][0] = '%c'\n", av[1][0]);
	printf("DEBUG: !av[1][0] = %d\n", !av[1][0]);

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		printf("DEBUG: Tomando path de return(1)\n");
		return (1);
	}
	else if (ac == 2)
	{
		printf("DEBUG: Antes del split, av[1] = '%s'\n", av[1]); // Añadir esto
		av = split(av[1], ' ');
		printf("DEBUG: Después del split, continuando...\n"); // Y esto
	}
	else
	{
		printf("DEBUG: Tomando path de ac > 2\n");
	}
	init_stack_a(&a, av + 1);
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
	return (0);
}
