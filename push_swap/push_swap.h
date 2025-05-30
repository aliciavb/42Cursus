/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:59:40 by avinals           #+#    #+#             */
/*   Updated: 2025/04/07 14:00:26 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h" 
# include <stddef.h> 

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

// stack_utils.c
t_node	*new_node(int value);
void	append_node(t_node **stack, t_node *new);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);

// error.c
void	exit_error(void);

// parser.c
int		is_number(char *str);
int		has_duplicates(t_node *stack);

// operations.c
void	sa(t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack);
void	rra(t_node **stack);

// sort_small.c
void	sort_3(t_node **stack);
int		is_sorted(t_node *stack);

#endif