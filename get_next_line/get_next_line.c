/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:53:53 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/14 16:00:38 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;	

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (*stash == '\0' || bytes_read < 0)
	{
		free(stash);
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (stash);
}

char	*ft_getstash(char *stash)
{
	char		*new_stash;
	int			line_len;

	line_len = 0;
	line_len = ft_strclen(stash, '\n') + 1;
	new_stash = ft_strndup(stash + line_len, ft_strlen(stash + line_len));
	free(stash);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;
	int				line_len;

	if (fd < 0)
		return (NULL);
	stash = ft_read_file(fd, stash);
	if (!stash)
		return (NULL);
	line_len = ft_strclen(stash, '\n') + 1;
	line = ft_strndup(stash, line_len);
	if (!line)
		return (NULL);
	stash = ft_getstash(stash);
	if (!stash)
		free(stash);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("example.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }