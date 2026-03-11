/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ymarmoud <ymarmoud@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/03/01 14:34:28 by ymarmoud		  #+#	#+#			 */
/*   Updated: 2026/03/11 22:42:20 by ymarmoud		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strdup(char *s)
{
	char	*sdup;
	int		i;

	if (!s)
		return (NULL);
	sdup = (char *)malloc(ft_strlen(s) + 1);
	if (!s)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s1s2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s1s2 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s1s2[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s1s2[i + j] = s2[j];
		j++;
	}
	s1s2[i + j] = '\0';
	return (s1s2);
}

char	*ft_strsub(char *s, int start, int len)
{
	char	*subs;
	int		i;

	if (!s || (start > ft_strlen(s)))
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	i = 0;
	subs = (char *)malloc(len +1);
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)(c))
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)(c))
		return ((char *)s + i);
	return (NULL);
}
