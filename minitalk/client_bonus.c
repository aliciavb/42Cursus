/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:32:55 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 13:05:01 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int g_received = 0;

void sigconfirm(int signal)
{
	(void)signal;
	g_received = 1;
}

void ft_send_signal(int pid, unsigned char character)
{
	int i;
	unsigned char temp_char;

	i = 8;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;

		g_received = 0;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);

		// Espera confirmación del server
		while (!g_received)
			usleep(50);
	}
}

int main(int ac, char **av)
{
	int pid;
	const char *message;
	int i;

	if (ac != 3)
	{
		ft_printf("Error. Try: ./client <PID> <MESSAGE>\n");
		return (1);
	}

	pid = ft_atoi(av[1]);
	message = av[2];

	// Configura el handler para recibir confirmaciones
	signal(SIGUSR1, sigconfirm);

	i = 0;
	while (message[i])
		ft_send_signal(pid, message[i++]);
	ft_send_signal(pid, '\0');

	ft_printf("Message sent successfully!\n");
	return (0);
}
