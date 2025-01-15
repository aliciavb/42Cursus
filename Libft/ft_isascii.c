/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:34:47 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/15 13:23:44 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int main(void)
{
	int c = 128;
	
	if (ft_isascii(c))
		printf("The character is %c\n", c);
	else
         printf("Cannot be represented by an ASCII character\n");
}
*/
