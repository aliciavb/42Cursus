/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:35:24 by avinals-          #+#    #+#             */
/*   Updated: 2025/03/10 16:05:56 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char **storer)
{
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

char	*handle_eof(char **storer)
{
	char	*line;

	if (**storer)
	{
		line = ft_strdup(*storer);
		free(*storer);
		*storer = NULL;
		return (line);
	}
	free(*storer);
	*storer = NULL;
	return (NULL);
}

char	*read_and_store(int fd, char **storer)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(*storer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(*storer);
			*storer = NULL;
			return (free(buffer), NULL);
		}
		if (bytes_read == 0)
			return (free(buffer), handle_eof(storer));
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*storer, buffer);
		free(*storer);
		*storer = temp;
	}
	free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storer[4096];
	char		*line_read;

	if (fd < 0)
		return (NULL);
	if (!storer[fd])
		storer[fd] = ft_strdup("");
	line_read = read_and_store(fd, &storer[fd]);
	if (line_read)
		return (line_read);
	if (storer[fd] && *storer[fd])
		return (extract_line(&storer[fd]));
	free(storer[fd]);
	storer[fd] = NULL;
	return (NULL);
}

/* int main(void)
{
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("single.txt", O_RDONLY);
	char *line;
	
	if (fd1 < 0 || fd2 < 0)
	{
		printf("Error opening file.\n");
		return (1);
	}
	if ((line = get_next_line(fd1)))
	{
		printf("->LINE fd1: %s\n", line);
		free(line);
	}
	if ((line = get_next_line(fd2)))
	{
		printf("->LINE fd2: %s\n", line);
		free(line);
	}
	if ((line = get_next_line(fd1)))
	{
		printf("->LINE fd1: %s\n", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	return (0);
} */
