/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:45:49 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 21:16:55 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief Finds the 'little' string inside the 'big'.
/// @param big String to search inside.
/// @param little String to look for.
/// @param len Maximum number of elements in 'big' to look for.
/// @return Returns a pointer to the first position of the 'big' string, where 'little' was found. If not found, returns '\0'.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*little))
		return ((char *)big);
	if (!len)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && big[i + j])
		{
			j++;
			if (!little[j])
				return ((char *)(&big[i]));
		}
		i++;
	}
	return (0);
}
