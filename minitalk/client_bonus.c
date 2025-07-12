/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:32:55 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 13:24:26 by avinals          ###   ########.fr       */
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

	// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
	ft_printf("%s[DEBUG] Sending char: '%c' (ASCII: %d)%s\n",
			  GRAY, character, character, RESET);
	// ===============================================================================

	i = 8;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;

		g_received = 0;
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

		// **BONUS**: Espera confirmación del servidor antes de enviar el siguiente bit
		while (!g_received)
			usleep(50);
	}

	// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
	ft_printf("%s[DEBUG] Character '%c' sent completely%s\n",
			  GREEN, character, RESET);
	ft_printf("%s────────────────────────────────%s\n", GRAY, RESET);
	// ===============================================================================
}

void ft_send_unicode_string(int pid, const char *message)
{
	int i;

	i = 0;
	// **BONUS**: Soporte Unicode - envía byte por byte (UTF-8)
	while (message[i])
	{
		ft_send_signal(pid, (unsigned char)message[i]);
		i++;
	}
	ft_send_signal(pid, '\0');
}

int main(int ac, char **av)
{
	int pid;
	const char *message;

	if (ac != 3)
	{
		ft_printf("Error. Try: ./client_bonus <PID> <MESSAGE>\n");
		return (1);
	}

	pid = ft_atoi(av[1]);
	message = av[2];

	// Configura el handler para recibir confirmaciones del servidor
	signal(SIGUSR1, sigconfirm);

	// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
	ft_printf("%s%sStarting transmission to PID: %d%s%s\n",
			  BOLD, CYAN, pid, RESET, RESET);
	ft_printf("%s═══════════════════════════════════════════════%s\n", CYAN, RESET);
	// ===============================================================================

	// **BONUS**: Envía mensaje con soporte Unicode
	ft_send_unicode_string(pid, message);

	// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
	ft_printf("%s%sTransmission completed!%s%s\n", BOLD, GREEN, RESET, RESET);
	// ===============================================================================

	return (0);
}
