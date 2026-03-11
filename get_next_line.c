/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ymarmoud <ymarmoud@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/03/01 14:34:01 by ymarmoud		  #+#	#+#			 */
/*   Updated: 2026/03/11 22:48:42 by ymarmoud		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_accumulate(int fd, char *s)
{
	char	*bf;
	int		r_byte;

	bf = (char *)malloc(BUFFER_SIZE + 1);
	if (!s)
		s = ft_strdup("");
	while ((r_byte = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		s = ft_strjoin(s, bf);
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(bf);
	return (s);
}

char	*extract_my_line(char *s)
{
	char	*l;
	int		i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	l = ft_strsub(s, 0, i + 1);
	return (l);
}

char	*update_my_save(char *s)
{
	char	*new_save;
	char	*ptr;

	ptr = ft_strchr(s, '\n');
	if (!ptr)
	{
		free(s);
		return (NULL);
	}
	new_save = ft_strdup(ptr + 1);
	free(s);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_accumulate(fd, save);
	if (!save)
		return (NULL);
	line = extract_my_line(save);
	save = update_my_save(save);
	return (line);
}
S
// int main()
// {
// 	int	 fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	// Loop until get_next_line returns NULL (End of File)
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line); // Print the line
// 		free(line);		 // Free the line to avoid memory leaks!
// 	}
// 	close(fd);
// 	return (0);
// }