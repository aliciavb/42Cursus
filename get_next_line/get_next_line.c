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
#include "get_next_line_utils.c"

char	*extract_line(char **storer)
{
	int		i = 0;
	char	*line;
	char	*new_storer;

	// Find first newline or end of `storer`
	while ((*storer)[i] && (*storer)[i] != '\n')
		i++;

	// Allocate memory for the line (include '\n' if present)
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, *storer, i + 1);
	line[i + 1] = '\0';

	// If there is text after `\n`, save it in `new_storer`
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
	static char	*storer = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*temp;

	// Initialize `storer` if it's NULL
	if (!storer)
		storer = ft_strdup("");

	// Read from file until a newline is found
	while (!ft_strchr(storer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';

		// Append new data to `storer`
		temp = ft_strjoin(storer, buffer);
		free(storer);
		storer = temp;
	}

	// Extract exactly one line from `storer`
	if (storer && *storer)
		return extract_line(&storer);

	// Cleanup on EOF
	free(storer);
	storer = NULL;
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

	// ✅ Process all lines in the file
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	printf("\n");
	close(fd);
	return (0);
}

