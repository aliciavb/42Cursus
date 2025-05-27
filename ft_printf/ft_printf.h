/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:50:04 by avinals           #+#    #+#             */
/*   Updated: 2025/03/24 15:05:36 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define BASE_UPPER "0123456789ABCDEF"
# define BASE_LOWER "0123456789abcdef"

int		ft_printf(char const *format, ...);
void	ft_putchar(char c, int *count);
void	ft_putstr(const char *str, int *count);
void	ft_putnbr(int nbr, int *count);
void	ft_putu(unsigned int nbr, int *count);
void	ft_putnbr_base(unsigned long str, char *base, int *count);
void	ft_putp(void *str, int *count);
void	ft_putlower(unsigned int nbr, int *count);
void	ft_putupper(unsigned int nbr, int *count);

#endif