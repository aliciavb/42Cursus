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
#include <stdio.h> // Para pruebas, eliminar en producción

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*temp;
	int		i;
	long	nb;

	stack_a = NULL;
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
	temp = stack_a;
	while (temp)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
	free_stack(&stack_a);
	return (0);
}
