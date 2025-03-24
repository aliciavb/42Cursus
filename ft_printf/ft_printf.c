/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:48:41 by avinals           #+#    #+#             */
/*   Updated: 2025/03/24 14:18:16 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(const char *str, int *count)
{
	while (*str)
	{
		ft_putchar(*str, count);
		str++;
	}
}

void	ft_putnbr(int nbr, int *count)
{
	if (nbr == INT_MIN)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
	}
	ft_putchar((nbr % 10) + '0', count);
	return ;
}

void	ft_putnbr_base(unsigned long str, char *base, int *count)
{
	if (str >= 16)
		ft_putnbr_base(str / 16, base, count);
	ft_putchar(base[str % 16], count);
}

void	ft_putp(void *str, int *count)
{
	long int	long_str;

	long_str = (unsigned long)str;
	ft_putstr("0x", count);
	ft_putnbr_base(long_str, BASE_LOWER, count);
}

/* formats to check: c s p d i u x X % */
int	check_format(va_list list, char str, int *count)
{
	if (str == 'c')
		ft_putchar(va_arg(list, int), count);
	else if (str == 's')
		ft_putstr(va_arg(list, char *), count);
	else if (str == 'p')
		ft_putp(va_arg(list, void *), count);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(list, int), count);
	/*else if (str == 'u')
		//
	else if (str == 'x')
		//
	else if (str == 'X')
		//*/
	return (*count);
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
			{
				check_format(list, *str, &count);
				str++;
			}
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

/* formats to check: c s p d i u x X % */
/* int main(void)
{
	//check no %
	printf("-%d\n", ft_printf("str-->"));
	printf("-%d\n", printf("str-->"));
	
	//check %c
	printf("-%d\n", ft_printf("%c", 'a'));
	printf("-%d\n", printf("%c", 'a'));
	
	//check %s
	printf("-%d\n", ft_printf("%s", "hello-->"));
	printf("-%d\n", printf("%s", "hello-->"));
	
	//check %p
	printf("-%d\n", ft_printf("%p", &ft_printf));
	printf("-%d\n", printf("%p", &ft_printf));
	
	//check %d
	printf("-%d\n", ft_printf("%d", 12));
	printf("-%d\n", printf("%d", 12));
	
	//check %i
	printf("-%d\n", ft_printf("%i", 012));
	printf("-%d\n", printf("%i", 012));
} */