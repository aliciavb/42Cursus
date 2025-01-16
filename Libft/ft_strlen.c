/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:45:44 by avinals-          #+#    #+#             */
/*   Updated: 2025/01/16 17:28:13 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* #include <stdio.h>
int main(void)
{
	char *str = "Cuentame este string";
	
	ft_strlen(str);
	printf("%d\n", ft_strlen(str));
	return (0);
} */