/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:33:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/09 11:15:58 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
