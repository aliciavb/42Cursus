/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:27:49 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/19 11:27:49 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	
	if (size <= len_dst)
		return (len_src + size);

	i = 0;
	while (src[i] != '\0' && (len_dst + i) < (size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/* #include <stdio.h>
int	main(void)
{
	char dst[50] = "Hello ";
	char src[50] = "worldssss";
	size_t size = 10;

	printf("Sin strlcat:\n");
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
	printf("size: %ld\n\n", size);

	ft_strlcat(dst, src, size);
	printf("Con strlcat:\n");
	printf("dst: %s\n", dst);

	return (0);
} */