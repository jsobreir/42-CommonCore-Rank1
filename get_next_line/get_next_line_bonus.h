/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:46:33 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/16 12:10:12 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef RONLY
#  define RONLY
# endif

# define MAX_FD 4096

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*read_file(int fd, char *stash);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, char c);
int			ft_strclen(char *str, char c);
char		*ft_strjoin(char *dest, char *src);
char		*ft_strndup(char *str, int n);
char		*ft_read_file(int fd, char *stash);

#endif