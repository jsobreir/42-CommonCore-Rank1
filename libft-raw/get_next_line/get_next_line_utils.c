/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:58:09 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/16 12:55:11 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
		i++;
	return (i);
}

int	ft_strclen(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (i != 0 && str[i] == '\0')
		i--;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str == c || !c)
		return (str);
	return (0);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*ret;
	int		len;
	char	*temp;
	char	*tmp_dest;

	len = ft_strlen(dest) + ft_strlen(src);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
	{
		free(dest);
		return (NULL);
	}
	temp = ret;
	tmp_dest = dest;
	while (dest != NULL && *dest)
		*(ret++) = *(dest++);
	while (*src)
		*(ret++) = *(src++);
	*ret = '\0';
	if (tmp_dest)
		free(tmp_dest);
	return (temp);
}

char	*ft_strndup(char *str, int n)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc((n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (str[i] != '\0' && i < n)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
