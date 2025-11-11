/* ************************************************************************** */	
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:03:13 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/11 12:00:38 by pifourni         ###   ########.fr       */
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
	rest = ft_calloc(j, sizeof(char));
	j = 0;
	i++;
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

char	*join_free(char *buffer, char *chunk)
{
	char	*temp;

	temp = ft_strjoin(buffer, chunk);
	free(buffer);
	return (temp);
}

char	*get_chunk(char *buffer, int fd)
{
	char	*chunk;
	int		data_read;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	chunk = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!chunk)
		return (NULL);
	while (1)
	{
		data_read = read(fd, chunk, BUFFER_SIZE);
		if (data_read < 0)
		{
			free(chunk);
			return (NULL);
		}
		if (data_read == 0)
			break ;
		buffer = join_free(buffer, chunk);
		if (!buffer)
		{
			free(chunk);
			return (NULL);
		}
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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = get_chunk(buffer, fd);
	if (!buffer || *buffer == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = get_line(buffer);
	buffer = get_rest(buffer);
	return (line);
	
}
