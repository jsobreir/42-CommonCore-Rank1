/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:35:22 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:36:42 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// @brief Searches for a char in a string.
/// @param s String to search.
/// @param c Char to search for.
/// @return Pointer to the found char in the string. NULL if not found.
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char )c)
		s++;
	if (*s == (char )c || !c)
		return ((char *) s);
	return (NULL);
}
