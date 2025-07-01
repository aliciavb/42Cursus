/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:50:31 by avinals-          #+#    #+#             */
/*   Updated: 2025/06/03 12:51:30 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//(Esto aún no es óptimo. 
// Luego optimizamos con lógica basada en índices bajos.)
void	push_all_but_3(t_node **a, t_node **b)
{
	int	size = stack_size(*a);
	int	i = 0;

	while (size > 3 && i < size)
	{
		pb(a, b);
		i++;
	}
}
