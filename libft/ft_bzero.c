/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:21 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:02:11 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

/// @brief Sets the values stored at a certain block of memory tto zero.
/// @param s Block of memory passed as a void pointer.
/// @param n Size of the block of memory.
void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		*((char *)s + i) = 0;
		i++;
		n--;
	}
}
