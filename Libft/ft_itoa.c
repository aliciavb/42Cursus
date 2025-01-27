/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:03:44 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/27 17:05:04 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		nbr;

	len = 1;
	nbr = n;
	while (nbr /= 10)
		len++;
	if (n < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	while (len-- > (n < 0))
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
int main(void)
{
	int n = 123;
	printf("%s\n", ft_itoa(n));
	return (0);
} */