/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:31:43 by avinals           #+#    #+#             */
/*   Updated: 2025/07/12 18:14:22 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_buffer = NULL;

void	reset_state(int *buffer_len, int *buffer_size, 
                int *bit_index, unsigned char *current_char, pid_t *client)
{
    if (g_buffer)
    {
        free(g_buffer);
        g_buffer = NULL;
    }
    *buffer_len = 0;
    *buffer_size = 0;
    *bit_index = 0;
    *current_char = 0;
    *client = 0;
}

void	expand_buffer(int *buffer_len, int *buffer_size, 
                    int *bit_index, unsigned char *current_char, pid_t *client)
{
    char	*new_buffer;

    *buffer_size = *buffer_size == 0 ? 1024 : *buffer_size * 2;
    new_buffer = malloc(*buffer_size);
    if (!new_buffer)
    {
        reset_state(buffer_len, buffer_size, bit_index, current_char, client);
        return ;
    }
    if (g_buffer)
    {
        ft_memcpy(new_buffer, g_buffer, *buffer_len);
        free(g_buffer);
    }
    g_buffer = new_buffer;
}

void	process_char(unsigned char c, int *buffer_len, int *buffer_size, 
                    int *bit_index, unsigned char *current_char, pid_t *client)
{
    if (c == '\0')
    {
        if (g_buffer && *buffer_len > 0)
        {
            g_buffer[*buffer_len] = '\0';
            ft_printf("%s\n", g_buffer);
        }
        reset_state(buffer_len, buffer_size, bit_index, current_char, client);
    }
    else
    {
        if (*buffer_len >= *buffer_size)
            expand_buffer(buffer_len, buffer_size, bit_index, current_char, client);
        if (g_buffer)
            g_buffer[(*buffer_len)++] = c;
    }
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
    static unsigned char	current_char = 0;
    static int				bit_index = 0;
    static int				buffer_len = 0;
    static int				buffer_size = 0;
    static pid_t			active_client = 0;

    (void)context;
    if (active_client != 0 && active_client != info->si_pid)
        return ;
    if (active_client == 0)
        active_client = info->si_pid;
    current_char = (current_char << 1) | (signal == SIGUSR1);
    bit_index++;
    if (bit_index == 8)
    {
        process_char(current_char, &buffer_len, &buffer_size, 
            &bit_index, &current_char, &active_client);
        bit_index = 0;
        current_char = 0;
    }
}

int	main(int ac, char **av)
{
    struct sigaction	sa;

    (void)av;
    if (ac != 1)
    {
        ft_printf("Error. Try: ./server\n");
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
