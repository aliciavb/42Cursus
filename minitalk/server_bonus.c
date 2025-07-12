/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:32:57 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 13:27:46 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int g_client_pid = 0;

void ft_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char current_char = 0;
	static int bit_index = 0;

	(void)context;
	g_client_pid = info->si_pid;

	// ========== DEBUG: Uncomment next line to see individual signals ==========
	// ft_printf("%s[DEBUG] Signal: %s from PID: %d, Bit: %d%s\n",
	//		  GRAY, (signal == SIGUSR1) ? "SIGUSR1" : "SIGUSR2",
	//		  g_client_pid, bit_index, RESET);
	// ==========================================================================

	current_char |= (signal == SIGUSR1);
	bit_index++;

	if (bit_index == 8)
	{
		// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
		ft_printf("%s════════════════════════════════════════%s\n", CYAN, RESET);
		ft_printf("%s[DEBUG] Complete char: '%c' (ASCII: %d)%s\n",
				  GREEN, current_char, current_char, RESET);
		ft_printf("%s════════════════════════════════════════%s\n", CYAN, RESET);
		// ===============================================================================

		if (current_char == '\0')
		{
			// ==================== DEBUG OUTPUT (REMOVE FOR PRODUCTION) ====================
			ft_printf("%s%s[MESSAGE END]%s%s\n", BOLD, YELLOW, RESET, RESET);
			// ===============================================================================
			ft_printf("\n");
		}
		else
		{
			// ==================== REAL SERVER OUTPUT - KEEP THIS ====================
			ft_printf("%c", current_char);
			// ========================================================================
		}
		bit_index = 0;
		current_char = 0;
	}
	else
	{
		current_char <<= 1;
		// ========== DEBUG: Uncomment next line to see shift operations ==========
		// ft_printf("%s[DEBUG] After shift: %d%s\n", GRAY, current_char, RESET);
		// ========================================================================
	}

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

	// ==================== REAL SERVER OUTPUT - KEEP THIS ====================
	ft_printf("PID: %d\n", getpid());
	ft_printf("Messages appear below\n");
	ft_printf("───────────────────────────────────────────────\n");
	// ========================================================================

	// Configurar sigaction para obtener información del cliente
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();

	return (0);
}