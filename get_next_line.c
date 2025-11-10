/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:03:13 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/10 16:48:27 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	int		r;

	buff = malloc(BUFFER_SIZE);
	if (!buff)
		return (NULL);
	r = read(fd, buff, BUFFER_SIZE);
	return (buff);
}
