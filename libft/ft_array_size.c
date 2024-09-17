/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:37:19 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 13:59:04 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Calculate the number of strings in an array.
/// @param array Double pointer-like array.
/// @return Size of the array.
int	ft_array_size(char **array)
{
	int	size;

	size = 0;
	while (*array)
	{
		array++;
		size++;
	}
	return (size);
}
