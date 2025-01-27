/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:02:30 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/27 13:25:03 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*substring_creator(const char *s, size_t n)
{
	char	*str;

	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		ptr_counter;

	str = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !str)
		return (NULL);
	i = 0;
	ptr_counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			str[ptr_counter++] = substring_creator(s + j, i - j);
	}
	str[j] = NULL;
	return (str);
}

int	main(void)
{
	char *s = "  This is a    string to split  ";
	char c = ' ';
	char **ptr = ft_split(s, c);
	int i = 0;

	while (ptr[i])
	{
		printf("ptr[%d]: %s\n", i, ptr[i]);
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}