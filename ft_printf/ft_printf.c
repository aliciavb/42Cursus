/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:48:41 by avinals           #+#    #+#             */
/*   Updated: 2025/03/17 18:28:39 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr(const char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

int	check_format(char const *str, va_list list)
{
	int count;
	
	count = 0;
	while (*str)
	{
		/* if (str[i] == 'c')
			//putchar; */
		if (*str == 's')
			count = putstr(va_arg(list, char *));
		/* if (str[i] == 'd')
			//putnbr;
		if (str[i] == 'u')
			//put unsigned nbr;
		if (str[i] == 'p')
			//putnbr with pointer base; */
		str++;
	}
	return(count);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	int		count;

	count = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				count = count + (check_format(str, list));
		}
		else
		{
			write(1, str++, 1);
			count++;
		}
	}
	va_end(list);
	return (count);
}

int main(void)
{
	//check no %
	printf("-%d\n", ft_printf("str\n"));
	printf("-%d\n", printf("str\n"));
	
	//check %s
	printf("-%d\n", ft_printf("%s", "hello\n"));
	printf("-%d\n", printf("%s", "hello\n"));
}