/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:01:32 by avinals-          #+#    #+#             */
/*   Updated: 2025/03/05 18:33:15 by avinals-         ###   ########.fr       */
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
	while (!ft_strchr(*storer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (handle_eof(storer));
			free (storer);
		}
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
	static char	*storer = NULL;
	char		*line_read;

	if (!storer)
		storer = ft_strdup("");
	line_read = read_and_store(fd, &storer);
	if (line_read)
		return (line_read);
	if (storer && *storer)
		return (extract_line(&storer));
	free(storer);
	storer = NULL;
	return (NULL);
}

/* int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	
	if (fd < 0)
	{
		printf("Error opening file.\n");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("->MAIN LINE: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
} */
