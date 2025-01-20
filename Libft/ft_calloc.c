/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:52:50 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/20 17:57:47 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
} 

int main(void)
{
	int *ptr;
	size_t nmemb = 5;
	size_t size = sizeof(int);

	ptr = ft_calloc(nmemb, size);
	if (ptr == NULL)
	{
		printf("Memory not allocated\n");
		return (0);
	}
	for (size_t i = 0; i < nmemb; i++)
		printf("%d\n", ptr[i]);
	free(ptr);
	return (0);
}