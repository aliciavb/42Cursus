/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:48:41 by avinals           #+#    #+#             */
/*   Updated: 2025/03/24 15:06:32 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (str == 'u')
		ft_putu(va_arg(list, unsigned int), count);
	else if (str == 'x')
		ft_putlower(va_arg(list, unsigned int), count);
	else if (str == 'X')
		ft_putupper(va_arg(list, unsigned int), count);
	else if (str == '%')
		ft_putchar('%', count);
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
	// check no %
	printf("-%d\n", ft_printf("str-->"));
	printf("-%d\n", printf("str-->"));

	// check %c
	printf("-%d\n", ft_printf("%c", 'a'));
	printf("-%d\n", printf("%c", 'a'));

	// check %s
	printf("-%d\n", ft_printf("%s", "hello-->"));
	printf("-%d\n", printf("%s", "hello-->"));

	// check %p
	printf("-%d\n", ft_printf("%p", &ft_printf));
	printf("-%d\n", printf("%p", &ft_printf));

	// check %d
	printf("-%d\n", ft_printf("%d", 12));
	printf("-%d\n", printf("%d", 12));

	// check %i
	printf("-%d\n", ft_printf("%i", 012));
	printf("-%d\n", printf("%i", 012));

	// check %u
    printf("-%d\n", ft_printf("%u", 1234567890));
    printf("-%d\n", printf("%u", 1234567890));

    // check %x
    printf("-%d\n", ft_printf("%x", 255));
    printf("-%d\n", printf("%x", 255));

    // check %X
    printf("-%d\n", ft_printf("%X", 255));
    printf("-%d\n", printf("%X", 255));

    // check %%
    printf("-%d\n", ft_printf("%%"));
    printf("-%d\n", printf("%%"));

    return 0;
} */