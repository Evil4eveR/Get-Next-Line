/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:01 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/05 00:36:09 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

	char	*result;
	if(!result)
		return NULL;
	read(fd, result, BUFFER_SIZE);
	// loop until you read all the text
	// find '\n'
	//
	return (result);
}
int main()
{
	printf("***********************************\n*    The_get_next_line project    *\n***********************************\n***********************************\n");



	int f = open("text.txt",O_RDONLY);
	printf("%s\n", get_next_line(f));    
	return 0;
}