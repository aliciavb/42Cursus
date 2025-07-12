/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:31:43 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 13:15:14 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_handler(int signal)
{
	static unsigned char current_char = 0;
	static int bit_index = 0;

	// ========== DEBUG: Uncomment next line to see individual signals ==========
	// ft_printf("%s[DEBUG] Signal: %s, Bit: %d, Char: %d%s\n",
	//		  GRAY, (signal == SIGUSR1) ? "SIGUSR1" : "SIGUSR2",
	//		  bit_index, current_char, RESET);
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
			ft_printf("\n"); // Real server output - keep this
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
}

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Error. Try: ./server\n");
		return (1);
	}

	// ==================== REAL SERVER OUTPUT - KEEP THIS ====================
	ft_printf("PID: %d\n", getpid()); // Required by subject
	ft_printf("Messages appear below\n");
	ft_printf("───────────────────────────────────────────────\n");
	// ========================================================================

	// ========== DEBUG: Comment out next 3 lines for colored PID ==========
	// ft_printf("%s%sPID: %d%s%s\n", BOLD, GREEN, getpid(), RESET, RESET);
	// ft_printf("%sMessages appear below%s\n", CYAN, RESET);
	// ft_printf("%s───────────────────────────────────────────────%s\n", CYAN, RESET);
	// ======================================================================

	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);

	while (1)
		pause();

	return (0);
}