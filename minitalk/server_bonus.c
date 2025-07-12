/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:32:57 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 13:51:44 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int g_client_pid = 0;

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;

	current_char = 0;
	bit_index = 0;
	(void)context;
	g_client_pid = info->si_pid;
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	// **BONUS**: Confirma cada señal recibida enviando SIGUSR1 al cliente
	kill(g_client_pid, SIGUSR1);
}

int main(int ac, char **av)
{
	struct sigaction sa;

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