/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:02:30 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/03 20:05:34 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "libft.h"

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
		{
			str[ptr_counter++] = substring_creator(s + j, i - j);
			if (!str)
			{
				return (NULL);
				free(str);
			}
		}
	}
	str[ptr_counter] = NULL;
	return (str);
} */
/* int	main(void)
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
}  */

#include "libft.h"

static size_t	ft_count_str(char const *s, char c)
{
	size_t	i;
	size_t	str_count;

	i = 0;
	str_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			i++;
			str_count++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (str_count);
}

static size_t	ft_word_len(const char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	return (i);
}

static char	*ft_paste_word(const char *src, char c)
{
	size_t	i;
	char	*dest;

	dest = ft_calloc(ft_word_len(src, c) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	*ft_free(char **arr, size_t iterator)
{
	while (iterator > 0)
		free(arr[--iterator]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	arr = (char **)ft_calloc(sizeof(char *), ft_count_str(s, c) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			arr[j] = ft_paste_word((char *)s + i, c);
			if (arr[j] == NULL)
				return (ft_free(arr, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
