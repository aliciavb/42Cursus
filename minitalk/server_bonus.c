/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:32:57 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 17:48:48 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	curr_char = 0;
	static int				bit_index = 0;

	(void)context;
	curr_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (curr_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", curr_char);
		bit_index = 0;
		curr_char = 0;
	}
	else
		curr_char <<= 1;
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error. Try: ./server_bonus\n");
		return (1);
	}
	ft_printf("PID: %d\n", getpid());
	ft_printf("Messages appear below\n");
	ft_printf("───────────────────────────────────────────────\n");
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
