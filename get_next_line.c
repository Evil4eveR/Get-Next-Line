/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:01 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/08 00:02:30 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	char *puffer;
// 	char *vorrat;
// 	int b_gelesen;

// 	puffer = malloc(BUFFER_SIZE +1);
// 	if(!puffer)
// 		return NULL;
// 	while(b_gelesen>0)
// 		{
			 
// 		}
// 		return vorrat;
// }
int main()
{
	printf("***********************************\n*    The_get_next_line project    *\n***********************************\n***********************************\n");


	// open it is a function return int which is file descriptor 
	// open takes 2 argement, and ...
	// first arg is char * the path of the file to be readed
	// second arg is int which is O_RDONLY or O_WDONLY to read or write 
	// if the second option is O_CREAT the third arg should be added
	// third arg is to describe the permission of the file created 
	int f = open("text.txt",O_RDONLY);
	
	char *buf;
	int sizeb = 6;
	buf = malloc(sizeb);
	printf("%d\n",f);
	//printf("%d\n",);
	while (read(f,buf,sizeb) != 0)
	{
		printf("%s",buf);
	}
	free(buf);
	return 0;
}