/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:12:54 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/14 16:01:46 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef RONLY
#  define RDONLY 00
# endif

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, char c);
int			ft_strclen(char *str, char c);
char		*ft_strjoin(char *dest, char *src);
char		*ft_strndup(char *str, int n);
char		*ft_read_file(int fd, char *stash);

#endif