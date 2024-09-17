/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:24:55 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief Function to find a given char in a block of memory.
/// @param s Pointer to the block of memory.
/// @param c Char to look for.
/// @param n Number of memory addresses to look in.
/// @return Pointer to the memory location of the char. Returns NULL if not found.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char )c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
