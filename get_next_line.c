/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:01 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/15 23:26:22 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*readandaccum(int fd, char	*stash)
{
	char	*buf;
	char	*tmp;
	ssize_t	r;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	r = 1;
	while (r > 0 && !ft_strchr(stash, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), free(stash), NULL);
		buf[r] = '\0';
		if (r > 0)
		{
			tmp = ft_strjoin(stash, buf);
			if (!tmp)
				return (free(buf), free(stash), NULL);
			free(stash);
			stash = tmp;
		}
	}
	free(buf);
	return (stash);
}

static char	*clean_stash(char *stash)
{
	char	*new;
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new = ft_strdup(stash + i + 1);
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL, NULL);
	stash = readandaccum(fd, stash);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	if (!line || !*line)
		return (free(stash), stash = NULL, NULL);
	stash = clean_stash(stash);
	return (line);
}
