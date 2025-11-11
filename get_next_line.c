/* ************************************************************************** */	
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:03:13 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/11 11:10:43 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_rest(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[i + j] != '\0')
		j++;
	rest = ft_calloc(i - j + 1, sizeof(char));
	j = 0;
	while (buffer[i + j] != '\0')
	{
		rest[j] = buffer[i + j];
		j++;
	}
	free(buffer);
	return (rest);
}

char	*get_line(char	*buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*get_chunk(char *buffer, int fd)
{
	char	*chunk;

	if (!buffer)
		ft_calloc(1, sizeof(char));
	chunk = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!chunk)
		return (NULL);
	while (read(fd, chunk, BUFFER_SIZE) > 0)
	{
		buffer = ft_strjoin(buffer, chunk);
		if (!buffer)
			return (NULL);
		if (has_nl(buffer))
			break ;
	}
	free(chunk);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	buffer = get_chunk(buffer, fd);
	if (!buffer)
	{
		return (NULL);
	}
	line = get_line(buffer);
	buffer = get_rest(buffer);
	return (line);
	
}
