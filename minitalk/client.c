/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:31:40 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 13:14:59 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_send_signal(int pid, unsigned char character)
{
	int i;
	unsigned char temp_char;

	// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
	ft_printf("%s[DEBUG] Sending char: '%c' (ASCII: %d)%s\n",
			  GRAY, character, character, RESET);
	// ===============================================================================

	i = 8;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;

		if (temp_char % 2 == 0)
		{
			// ========== DEBUG: Uncomment next line to see individual bits ==========
			// ft_printf("%s[DEBUG] Bit %d: 0 -> SIGUSR2%s\n", GRAY, 7 - i, RESET);
			// =======================================================================
			kill(pid, SIGUSR2);
		}
		else
		{
			// ========== DEBUG: Uncomment next line to see individual bits ==========
			// ft_printf("%s[DEBUG] Bit %d: 1 -> SIGUSR1%s\n", GRAY, 7 - i, RESET);
			// =======================================================================
			kill(pid, SIGUSR1);
		}
		usleep(500);
	}

	// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
	ft_printf("%s[DEBUG] Character '%c' sent completely%s\n",
			  GREEN, character, RESET);
	ft_printf("%s────────────────────────────────%s\n", GRAY, RESET);
	// ===============================================================================
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
	i = 0;

	// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
	ft_printf("%s%sStarting transmission to PID: %d%s%s\n",
			  BOLD, CYAN, pid, RESET, RESET);
	ft_printf("%s═══════════════════════════════════════════════%s\n", CYAN, RESET);
	// ===============================================================================

	while (message[i])
		ft_send_signal(pid, message[i++]);
	ft_send_signal(pid, '\0');

	// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
	ft_printf("%s%sTransmission completed!%s%s\n", BOLD, GREEN, RESET, RESET);
	// ===============================================================================

	return (0);
}