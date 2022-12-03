/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:20:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/14 00:50:45 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_leftover(char *memory)
{
	char	*leftover;
	size_t	jump;
	size_t	len;

	len = ft_strclen(memory, '\0');
	jump = ft_strclen(memory, '\n');
	if (memory[jump] == '\n')
		jump++;
	leftover = ft_strndup(memory + jump, len - jump + 1);
	if (!leftover)
		return (NULL);
	free(memory);
	return (leftover);
}

char	*get_line(char *memory)
{
	char	*line;
	size_t	len;

	len = ft_strclen(memory, '\n');
	if (memory[len] == '\n')
		len++;
	line = ft_strndup(memory, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*store_chunks(int fd, char *memory)
{
	char	*chunk;
	ssize_t	bytes;

	bytes = 1;
	chunk = (char *)malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	while (bytes > 0 && !ft_strchr(memory, '\n'))
	{
		bytes = read(fd, chunk, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free(chunk);
			return (NULL);
		}
		chunk[bytes] = '\0';
		memory = ft_strjoin(memory, chunk);
	}
	free(chunk);
	if (ft_strclen(memory, '\0') > 0)
		return (memory);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*memory[MAX_FILES];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FILES)
		return (NULL);
	memory[fd] = store_chunks(fd, memory[fd]);
	if (!memory[fd])
		return (NULL);
	line = get_line(memory[fd]);
	memory[fd] = get_leftover(memory[fd]);
	if (!memory[fd][0])
	{
		free(memory[fd]);
		memory[fd] = NULL;
	}
	return (line);
}
