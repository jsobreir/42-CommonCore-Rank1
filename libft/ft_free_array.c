/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:33:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:04:50 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Frees an array.
/// @param array Pointer to the address of the first array element.
/// @param size Size of the array to be freed.
void	ft_free_array(char **array, int size)
{
	while (size > 0)
	{
		free(array[size]);
		size--;
	}
	free(array);
	return ;
}
