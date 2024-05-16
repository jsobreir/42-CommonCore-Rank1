/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:50:11 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/16 12:44:59 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read && BUFFER_SIZE >= 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
		if (*stash == '\0' || bytes_read < 0)
			return (free(stash), free(buffer), NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_getstash(char *stash)
{
	char	*new_stash;
	int		line_len;

	line_len = ft_strclen(stash, '\n');
	new_stash = ft_strndup(stash + line_len + 1, ft_strlen(stash));
	if (!new_stash)
		return (NULL);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char		*stash[MAX_FD];
	char			*line;
	int				line_len;

	if (fd < 0 && fd > 4096)
		return (NULL);
	if (!stash[fd])
		stash[fd] = NULL;
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line_len = ft_strclen(stash[fd], '\n');
	line = ft_strndup(stash[fd], line_len + 1);
	if (!line)
		return (NULL);
	stash[fd] = ft_getstash(stash[fd]);
	if (!stash[fd])
		free(stash[fd]);
	return (line);
}

// int main()
// {
// 	int fd = open("example.txt", O_RDONLY);
// 	int fd1 = open("example2.txt", O_RDONLY);
// 	int fd2 = open("example3.txt", O_RDONLY);
// 	int i = 0;
// 	while(i < 4)
// 	{
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd1));
// 		printf("%s", get_next_line(fd2));
// 		i++;
// 	}
// 	return(0);
// }

// int main(void)
// {
//     int     fd1;
//     int     fd2;
//     char    *path1 = "./example.txt";
//     char    *path2 = "./example2.txt";
//     char    *str;

//     fd1 = open(path1, O_RDONLY);
//     fd2 = open(path2, O_RDONLY);
//     int     fd[] = {fd1, fd2};
//     printf("file descriptor number: %d\n", fd1);
//     printf("file descriptor number: %d\n", fd2);
//     str = "init";
//     while (str != NULL)
//     {
//         str = get_next_line(fd[0]);
//         printf ("%s", str);
//         free(str);
//         str = get_next_line(fd[1]);
//         printf ("%s", str);
//         free(str);
//     }
//     close(fd[0]);
//     close(fd[1]);
//     return (0);
// }