/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:32:55 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 17:59:03 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_read_receipt(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Received bit 1 confirmation\n");
	else if (signal == SIGUSR2)
		ft_printf("Received bit 0 confirmation\n");
}

void	ft_send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	int			pid;
	const char	*message;
	int			i;

	signal(SIGUSR1, handle_read_receipt);
	signal(SIGUSR2, handle_read_receipt);
	if (ac != 3)
	{
		ft_printf("Error. Try: ./client_bonus <PID> <MESSAGE>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	i = 0;
	while (message[i])
		ft_send_signal(pid, message[i++]);
	ft_send_signal(pid, '\0');
	return (0);
}
