/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:27:13 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/17 15:27:38 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	i = 0;
	if (size > 0)
	{
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

#include <stdio.h>
int main(void)
{
	char str[] = "Hellu wurld";
	char temp[10];
	unsigned int len;
	
	len = ft_strlcpy(temp, str, 8);
	printf("El string en dest es: '%s'\n", temp);
	printf("La longitud del string en src es: %u\n", len);
}