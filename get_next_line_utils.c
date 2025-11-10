/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <pifourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:52:03 by pifourni          #+#    #+#             */
/*   Updated: 2025/11/10 23:45:39 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_nl(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	return (buffer[i] == '\n');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*res;

	if (nmemb != 0 && size > ((size_t)-1) / nmemb)
	{
		return (NULL);
	}
	res = malloc(nmemb * size);
	if (res == NULL)
	{
		return (res);
	}
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)res)[i] = 0;
		i++;
	}
	return (res);
}
