/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:58:55 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:43:19 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies a string src to a dest memory block. The memory block dest shall contain enough memory for src, otherwise the '\0' char nay be overwritten!
/// @param dest Destination memory block to copy to.
/// @param src Source to copy.
/// @param n Number of memory elements to copy from src.
/// @return Length of the resulting string.
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
