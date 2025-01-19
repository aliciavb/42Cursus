/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:55:39 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/19 11:55:39 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;
	
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return ((char *)&s[i]);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
	char *str = "Hello world";
	char c = 'z';
	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));
	return (0);
} 