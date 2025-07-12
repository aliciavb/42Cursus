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

static char	*g_buffer = NULL;

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_index = 0;
	static int				buffer_len = 0;
	static int				buffer_size = 0;

	(void)context;
	current_char = (current_char << 1) | (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			if (g_buffer)
			{
				g_buffer[buffer_len] = '\0';
				ft_printf("%s\n", g_buffer);
				free(g_buffer);
				g_buffer = NULL;
			}
			else
				ft_printf("\n");
			buffer_len = 0;
			buffer_size = 0;
		}
		else
		{
			if (buffer_len >= buffer_size)
			{
				buffer_size = buffer_size == 0 ? 1024 : buffer_size * 2;
				char *new_buffer = malloc(buffer_size);
				if (!new_buffer)
				{
					ft_printf("\n[ERROR] Memory allocation failed\n");
					if (g_buffer)
						free(g_buffer);
					g_buffer = NULL;
					buffer_len = 0;
					buffer_size = 0;
					bit_index = 0;
					current_char = 0;
					return ;
				}
				if (g_buffer)
				{
					ft_memcpy(new_buffer, g_buffer, buffer_len);
					free(g_buffer);
				}
				g_buffer = new_buffer;
			}
			g_buffer[buffer_len++] = current_char;
		}
		bit_index = 0;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
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
