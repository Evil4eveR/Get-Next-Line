/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:28 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/08 17:18:54 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int cnt;

	cnt = 0;
	while(s[cnt])
		cnt++;
	return (cnt);
}
char	*ft_strdup(char *s)
{
	char	*sdup;
	int	i;

	i = 0;
	sdup = (char *)malloc(ft_strlen(s)+1);
	if(!sdup)
		return (NULL);
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
	size_t	i;

	if(!s)
		return (NULL);
	if(start>ft_strlen(s))
		return(ft_strdup(""));
	if(l>ft_strlen(s)-start)
		l = ft_strlen(s) - start;	
	subs = (char *)malloc(l+1);
	if(!subs)
		return (NULL);
	i = 0;
	while(s[start+i] && i<l)
	{
		subs[i]=s[start+i];
		i++;
	}
	subs[i]='\0';
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

char	*ft_check(char	*tmp, char *buf, ssize_t rb)
{
	char	*keep_tmp;
	size_t	len;

	len = 0;
	keep_tmp = NULL;
	if(tmp)
	{
		keep_tmp = ft_strdup(tmp);
		free(tmp);
		len = ft_strlen(keep_tmp) + ft_strlen(buf);
		tmp = (char *)malloc(len + 1);
		if(!tmp)
			return (NULL);
		ft_mmcpy(tmp, keep_tmp, ft_strlen(keep_tmp)+1);
		tmp[ft_strlen(keep_tmp)]= '\0';
		ft_mmcpy(ft_strchr(tmp, '\0'), buf, ft_strlen(buf)+1);
		tmp[len]= '\0';
		free(keep_tmp);
	}
	else if(!tmp)
		tmp = ft_strdup(buf);
	return (tmp);
}

void	ft_extract(char **ptr)
{
	char *keep_tmp;

	keep_tmp = ft_strdup(ft_strchr(*ptr, '\n')+1);
	free(*ptr);

}

char	*ft_free(char **ptr_tmp,char **ptr_buf, size_t b)
{
	char *line;

	line = NULL;
	if(*ptr_tmp && **ptr_tmp && b==0)
	{
		line = ft_strdup(*ptr_tmp);
		free(*ptr_tmp);
		*ptr_tmp = NULL;
		free(*ptr_buf);
		*ptr_buf = NULL;
		return (line);
	}
	if(ft_strchr(*ptr_tmp,'\n')!= NULL)
	{
		line = ft_substr(*ptr_tmp, 0, ft_strlen(*ptr_tmp)-ft_strlen(ft_strchr(*ptr_tmp, '\n'))+1);
		ft_extract(ptr_tmp);
		return (line);
	}
	free(*ptr_tmp);
	*ptr_tmp = NULL;
	free(*ptr_buf);
	*ptr_buf = NULL;
	return (NULL);
}