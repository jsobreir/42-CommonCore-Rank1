/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:45:18 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:37:32 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief Allocates space for a duplicate of a string s. Dublicates to that space.
/// @param s String to duplicate.
/// @return Pointer to the duplicate string.
char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;
	int		i;

	len = ft_strlen(s);
	ret = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!ret)
		return (0);
	while (*s)
	{
		ret[i] = *s;
		s++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
