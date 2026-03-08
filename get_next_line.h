/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:44 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/03 15:19:45 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_substr(char	*s, unsigned int start, size_t l);
void	*ft_mmcpy(void	*des, void const *src, size_t n);
char	*ft_strchr(char	*s, int c);


char	*ft_check(char	*tmp, char *buf, ssize_t rb);
char	*ft_free(char **ptr_tmp,char **ptr_buf, size_t b);
void	ft_extract(char **ptr);
#endif

