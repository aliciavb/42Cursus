/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:34:47 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/16 17:26:46 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
int main(void)
{
	int c = 128;
	
	if (ft_isascii(c))
		printf("El caracter es %c\n", c);
	else
         printf("No se puede representar en ASCII\n");
} */