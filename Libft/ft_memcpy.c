/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:18:25 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/17 14:03:55 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
int main(void)
{
    char src[50] = "Str en source";
    char dest[50];

    printf("Sin memcpy:\n");
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);

    ft_memcpy(dest, src, 25);

    printf("Con ft_memcpy:\n");
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);

    return 0;
} */