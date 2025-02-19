/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:01:32 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/19 13:44:19 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//copies n bytes from src to dest even if they overlap
void	*ft_memcpy(void *dest, const void *src, size_t n);

//duplicates a string storing it in a new ptr
char	*ft_strdup(const char *s);

//finds first c in s
char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

char	*extract_line(char **storer)
{
	// FALTA AÑADIR UNA CONDICION QUE IMPRIMA LA ULTIMA LINEA AUNQUE NO TENGA SALTO DE LINEA.
// SI STORER ES EL FINAL DEL ARCHIVO Y NO CONTIENE UN SALTO DE LINEA
// IMPRIME STORER
	int		i;
	char	*line;
	char	*new_storer;

	i = 0;
	while ((*storer)[i] && (*storer)[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, *storer, i + 1);
	line[i + 1] = '\0';
	if ((*storer)[i] == '\n' && (*storer)[i + 1] != '\0')
	{
		new_storer = ft_strdup(*storer + i + 1);
		free(*storer);
		*storer = new_storer;
	}
	else
	{
		free(*storer);
		*storer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storer;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*temp;
	static int i;

	if(!i)
		i = 0;
	printf("\nstorer = [%s]\n", storer);
	i++;
	printf("\n%d\n", i);
	if (!storer)
		storer = ft_strdup("");
	while (!ft_strchr(storer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(storer, buffer);
/* 		printf("[initial storer: %s]\n",storer);
		printf("[buffer after read: %s]\n",buffer);
		printf("[temp after joining storer and buffer: %s]\n",temp); */
		free(storer);
		storer = temp;
	}
	if (storer && *storer)
	{
		return (extract_line(&storer));
	}
	free(storer);
	storer = ft_strchr(storer, '\n');
	return (NULL);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	
	if (fd < 0)
	{
		printf("Error opening file.\n");
		return (1);
	}
/* 	printf("->MAIN LINE: %s", get_next_line(fd));
	printf("->MAIN LINE: %s", get_next_line(fd));

	printf("->MAIN LINE: %s", get_next_line(fd)); */
	while ((line = get_next_line(fd)))
	{
		printf("->MAIN LINE: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
