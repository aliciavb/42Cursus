/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutable_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:19:33 by avinals           #+#    #+#             */
/*   Updated: 2025/07/02 14:28:17 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	inside_word = false;
	while (*s)
	{
		if (*s != c && !inside_word)
		{
			inside_word = true;
			count++;
		}
		else if (*s == c)
			inside_word = false;
		s++;
	}
	return (count);
}

static char	*get_next_word(char **s, char c)
{
	char	*start;
	char	*word;
	int		len;
	int		i;

	while (**s == c)
		(*s)++;
	start = *s;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	*s += len;
	return (word);
}

char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (words_count + 2));
	if (!result_array)
		return (NULL);
	result_array[0] = malloc(1);
	if (!result_array[0])
		return (NULL);
	result_array[0][0] = '\0';
	i = 1;
	while (i <= words_count)
	{
		result_array[i] = get_next_word(&s, c);
		if (!result_array[i])
			return (NULL);
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}
