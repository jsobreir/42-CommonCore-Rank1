/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:37:19 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/09 11:08:21 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
