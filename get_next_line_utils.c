/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:28 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/07 22:23:31 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	cnt;

	cnt=0;
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t  i;
    unsigned char   *d;
    unsigned char   *s;

    if (!dst || !src)
        return (NULL);
    d = (unsigned char *) dst;
    s = (unsigned char *) src;
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dst);
}
