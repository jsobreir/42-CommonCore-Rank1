/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:56:34 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:38:25 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Iterattes a string and applies a given function to each element of the string.
/// @param s String to iterate.
/// @param f Void pointer to the function to apply.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (s && (*f))
	{
		while (*s)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
