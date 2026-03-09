/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:01 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/09 17:16:42 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd)
{
	static char *tmp;
	char *buffer;
	char *line;
	ssize_t	r_bytes;

	line = NULL;
	buffer = NULL;
	r_bytes = 1;
	if(fd<0 || BUFFER_SIZE <= 0 )
		return NULL;
	while (r_bytes != 0) 
	{
		if(ft_strchr(tmp,'\n') != NULL)
			return(ft_free(&tmp,&buffer,r_bytes));
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if(!buffer)
			return (NULL);
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if(r_bytes <= 0)
			break;
		free(tmp);
		tmp = NULL;
		free(buffer);
		buffer = NULL;
	}
	return (ft_free(&tmp, &buffer,r_bytes));
}

int main()
{
	printf("***********************************\n*    The_get_next_line project    *\n***********************************\n***********************************\n");
	int fd = 0;
	char *string = NULL;
	fd = open("text.txt",O_RDONLY);
	if(fd<0)
	{
		printf("error de lire le text\n");
		return (1);
	}
	string = get_next_line(fd);
	while(string)
	{
		printf("%s",string);
		string = get_next_line(fd);
	}
	
	return 0;
}