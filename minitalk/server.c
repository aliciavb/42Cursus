/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:31:43 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 13:53:04 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static unsigned char	current_char;
	static int				bit_index;

	current_char = 0;
	bit_index = 0;
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Error. Try: ./server\n");
		return (1);
	}
	ft_printf("PID: %d\n", getpid());
	ft_printf("Messages appear below\n");
	ft_printf("───────────────────────────────────────────────\n");
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
