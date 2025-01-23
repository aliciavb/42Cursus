/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:13:22 by avinals           #+#    #+#             */
/*   Updated: 2025/01/22 12:13:22 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s) + 1;
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s, len);
	return (ptr);
}

/* int main(void)
{
	char *s = "String to duplicate";
	char *ptr; // place in memory to store the dup string

	ptr = ft_strdup(s);
	if (ptr == NULL) 
	{
		printf("Allocation failed\n");
		return (0);
	}
	printf("%s\n", ptr);
	free(ptr);
	return (0);
} */