/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:27 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:28:42 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief Copies the values stored at a memory block to another.
/// @param dest Pointer to the destination block.
/// @param src Pointer to the source block.
/// @param n Maximum number of elements to copy.
/// @return Pointer to the destination block.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*source;
	char			*destination;
	size_t			i;

	source = src;
	destination = dest;
	if (!n || (!dest && !src))
		return (dest);
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	dest = destination;
	return (dest);
}
