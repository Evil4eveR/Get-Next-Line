/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:28 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/15 23:20:52 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s1s2;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	s1s2 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1s2)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		s1s2[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s1s2[i++] = s2[j++];
	s1s2[i] = '\0';
	return (s1s2);
}

char	*ft_strdup(char	*s)
{
	char	*sdup;
	size_t	i;

	if (!s)
		return (NULL);
	sdup = malloc(ft_strlen(s) + 1);
	if (!sdup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc (i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
