/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:03:44 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/03 20:16:07 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_strlen(int n)
{
	int		len;
	long	nb;

	nb = n;
	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	db_n;
	int		str_len;

	db_n = n;
	str_len = ft_itoa_strlen(n);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	str[str_len--] = '\0';
	if (db_n == 0)
		str[0] = '0';
	else if (db_n < 0)
	{
		str[0] = '-';
		db_n *= -1;
	}
	while (db_n > 0)
	{
		str[str_len] = 48 + (db_n % 10);
		db_n /= 10;
		str_len--;
	}
	return (str);
}

/* int main(void)
{
	int n = 123;
	printf("%s\n", ft_itoa(n));
	return (0);
} */