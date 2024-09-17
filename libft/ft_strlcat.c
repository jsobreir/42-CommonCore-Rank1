/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:45:22 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:41:15 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief Concatenates size elements of a src string to a dest string. The dest shall contain sufficient memory allocated for the src.
/// @param dst Destination string.
/// @param src Source string.
/// @param size Number of elements of the src string to concatenate.
/// @return Length of the concatenated string.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	if ((!dst || !src) && !size)
		return (0);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	i = 0;
	if (size > 0 && dest_len < size - 1)
	{
		while (src[i] && dest_len + i < size - 1)
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		dst[dest_len + i] = '\0';
	}
	if (dest_len >= size)
		dest_len = size;
	return (dest_len + src_len);
}
