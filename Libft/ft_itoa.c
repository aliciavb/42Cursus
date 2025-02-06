/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:03:44 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:19:01 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Returns the number of digits in the integer received as an argument.
static int	ft_numlen(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

//Copies the integer received as an argument to a string.
static void	ft_strnum(int nb, char *str, int len)
{
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
}

//Returns a string representing the integer received as an argument.
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == INT_MIN)
	{
		ft_memcpy(str, "-2147483648", 12);
		return (str);
	}
	ft_strnum(n, str, len);
	return (str);
}

/* int main(void)
{
	int n = 123;
	printf("%s\n", ft_itoa(n));
	return (0);
} */