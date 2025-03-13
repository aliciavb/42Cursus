/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:48:41 by avinals           #+#    #+#             */
/*   Updated: 2025/03/13 11:48:41 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_parse_format(const char **format, va_list args)
{
	char *str;
	int count;

	count = 0;
	if (**format == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (**format == 'd')
		str = ft_itoa(va_arg(args, int));
	else if (**format == 'x')
		str = ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (**format == 'X')
		str = ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else
	{
		str = (char *)malloc(2);
		str[0] = **format;
		str[1] = '\0';
	}
	(*format)++;
	return (str);
}

/* ft_vprintf handles formatted output with a variable number
 of arguments, leveraging the va_list type to manage arguments dynamically.
 This function is used to create custom formatted output functions
 that can handle a flexible number of input parameters. */
int ft_vprintf(const char *format, va_list args)
{
	int count;
	char *str;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			str = ft_parse_format(&format, args);
			count += ft_putstr(str);
			free(str);
		}
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = ft_vprintf(format, args);
	va_end(args);
	return (count);
}

int main(void)
{
	ft_printf("Hello, %s! %d %x %X\n", "world", 42, 42, 42);
	printf("Hello, %s! %d %x %X\n", "world", 42, 42, 42);

	ft_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');

	ft_printf("String: %s\n", "Test string");
	printf("String: %s\n", "Test string");

	ft_printf("Pointer: %p\n", (void *)0x12345678);
	printf("Pointer: %p\n", (void *)0x12345678);

	ft_printf("Decimal: %d\n", 12345);
	printf("Decimal: %d\n", 12345);

	ft_printf("Integer: %i\n", -12345);
	printf("Integer: %i\n", -12345);

	ft_printf("Unsigned: %u\n", 12345);
	printf("Unsigned: %u\n", 12345);

	ft_printf("Hexadecimal (lowercase): %x\n", 0xabcdef);
	printf("Hexadecimal (lowercase): %x\n", 0xabcdef);

	ft_printf("Hexadecimal (uppercase): %X\n", 0xABCDEF);
	printf("Hexadecimal (uppercase): %X\n", 0xABCDEF);

	return (0);
}