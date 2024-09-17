/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:40 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:32:21 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief Sets n bytes of memory to a certain int value.
/// @param s Memory block to affect.
/// @param c Value to set the memory at.
/// @param n Number of memory locations to affect.
/// @return POointoer to the memory block.
void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		*(unsigned char *)(s + i) = (unsigned char )c;
		n--;
		i++;
	}
	return (s);
}
