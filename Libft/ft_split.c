/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:02:30 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/23 13:02:30 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL)
		return (NULL);
	ptr = malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			k = 0;
			ptr[j] = malloc(ft_strlen(s) + 1);
			if (ptr[j] == NULL)
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				ptr[j][k++] = s[i++];
			ptr[j++][k] = '\0';
		}
		else
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}
