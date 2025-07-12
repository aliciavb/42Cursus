/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:32:55 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 12:54:30 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int g_client_pid = 0;

void	ft_handler(int signal, siginfo_t *info, void *context)
{
    static unsigned char	current_char = 0;
    static int				bit_index = 0;

    (void)context;
    g_client_pid = info->si_pid;
    
    current_char |= (signal == SIGUSR1);
    bit_index++;
    
    if (bit_index == 8)
    {
        if (current_char == '\0')
            ft_printf("\n");
        else
            ft_printf("%c", current_char);
        bit_index = 0;
        current_char = 0;
    }
    else
        current_char <<= 1;
    
    // Confirma cada señal recibida
    kill(g_client_pid, SIGUSR1);
}

