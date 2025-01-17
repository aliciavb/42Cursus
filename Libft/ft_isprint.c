/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:27:22 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/16 17:26:25 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
int main(void)
{
    char c = '\a'; 
    
    if (ft_isprint(c))
        printf("El caracter es %c\n", c);
    else
         printf("No se puede imprimir\n");
} */