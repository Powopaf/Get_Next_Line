/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:03:13 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/10 23:48:21 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *
 * read the file until by chunk of BUFFER SIZE put all of it in the static
 * buffer. when \n or \0 found in the static create a newline that end with \n
 * and return it
 * remove the line of the static buffer if last char of the next line is \0 ->
 * we have reach the end of file static buffer must be free and = NULL
 *
 * TODO: ft_strjoin -> libft
 * TODO: find_nl -> look for newline 
*/

char *get_rest(char *buff)
{
	//TODO: erase the last line from the buffer because it has already been read
}

char	*get_line(char	*buffer)
{
	//TODO: return a line that must end with \n
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
