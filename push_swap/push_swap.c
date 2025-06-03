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
#include "Libft/libft.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	long	nb;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			exit_error();
		nb = ft_atoi(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
			exit_error();
		append_node(&stack_a, new_node((int)nb));
		i++;
	}
	if (has_duplicates(stack_a))
		exit_error();

	if (stack_size(stack_a) == 3)
	sort_3(&stack_a);

	if (!is_sorted(stack_a))
{
	index_stack(stack_a);
	if (stack_size(stack_a) == 2)
		sort_2(&stack_a);
	else if (stack_size(stack_a) == 3)
		sort_3(&stack_a);
	else
	{
		push_all_but_3(&stack_a, &stack_b);
		sort_3(&stack_a);
		// Aquí vendrá la lógica de reinserción desde B
	}
}

	// más adelante: else if (size <= 5) sort_5(...); etc.

	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
