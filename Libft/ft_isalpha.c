/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:37:54 by avinals           #+#    #+#             */
/*   Updated: 2025/01/14 18:37:54 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z')
            || (c >= 'a' && c <= 'z'))
            return (1);
    return (0);
}

/*#include <stdio.h>
int main(void)
{
    int c = 'A';

    ft_isalpha(c);
    if (ft_isalpha(c))
        printf("1\n");
    else
        printf("0\n");
}*/