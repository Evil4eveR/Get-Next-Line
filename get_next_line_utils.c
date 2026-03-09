/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:28 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/09 17:34:07 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*s)
{
	size_t	cnt;

	cnt = 0;
	while(s[cnt])
		cnt++;
	return (cnt);
}

ft_strdup(char	*s)
{
	char	*sdup;
	int		i;

	sdup = (char *)malloc(ft_strlen(s)+1);
	if(!sdup)
		return (NULL);
	i = 0;
	while(s[i])
	{
		sdup[i]=s[i];
		i++;
	}
	sdup[i]='\0';
	return (sdup);
}
char	*ft_substr(char	*s, unsigned int start, size_t l)
{
	char	*subs;
	size_t		i;

	if(!s)
		return (NULL);
	if(start>ft_strlen(s))
		return(ft_strdup(""));
	if (l > ft_strlen(s) - start)
		l = ft_strlen - start;
	subs =(char *)malloc(l+1);
	if(!subs)
		return (NULL);
	i = 0;
	while(s[start+i] && i < l)
	{
		subs[i] = s[start+i];
		i++;
	}
	subs[i]= '\0';
	return (subs);
}

void	*ft_mmcpy(void	*des, void const *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t	i;

	d = (unsigned char	*)des;
	s = (unsigned char	*)src;
	if (!des && !src)
		return (NULL);
	i = 0;
	while(i < n)
	{
		d[i]=s[i];
		i++;
	}
	d[i]='\0';
	return (d);
}

char	*ft_strchr(char	*s, int c)
{
	if(!s && c!='\0')
		return (0);
	while(*s)
	{
		if(*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}