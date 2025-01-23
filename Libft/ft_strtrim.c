/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:07:58 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/23 12:07:58 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
    char	*ptr;
    size_t	len;

	len = ft_strlen(s1); //calculate initial length
    if (s1 == NULL || set == NULL) 
        return (NULL);
    while (*s1 != '\0' && (ft_strchr(set, *s1))) //look for set char in s1
    {
        s1++; // move pointer one position to the right
        len--; // decrease length by one (becouse of s1++)
    }
    while (len > 0 && (ft_strchr(set, s1[len - 1]))) //look for set char in s1
        len--; // move pointer to the left

    ptr = ft_substr(s1, 0, len); //create a new string with the new length
    return (ptr);
}

/* int main(void)
{
	char *s1 = "  \tString to trim  \t";
	char *set = " \t";

	printf("%s\n", ft_strtrim(s1, set));
	
	free(ft_strtrim(s1, set));
	return (0);
} */