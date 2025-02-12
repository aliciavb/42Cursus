/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:01:32 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/12 13:58:23 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//ssize_t read(int fd, void *buf, size_t nbyte)
char	*get_next_line(int fd)
{
	char buf[50];
	static char *chunk = NULL;
	char *temp;
	int reading;
	
	reading = read(fd, buf, 10);

	if (reading == 0)
		return (chunk);
	if (reading == -1)
		return (NULL);
	while (!(ft_strchr(chunk, '\n')))
	{
		temp = ft_strjoin(chunk, buf);
		free(chunk);
		chunk = temp;
	}
	
	return(chunk);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	
	printf("%s\n", get_next_line(fd));
}