/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:35 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:31:14 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief Copies n bytes from memory area src to memory area dest.  The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array
/// that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.
/// @param dest Destination memory block.
/// @param src Source memory block.
/// @param n Number of elements to move.
/// @return Pointer to the destination memory block.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = (int)n - 1;
	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
