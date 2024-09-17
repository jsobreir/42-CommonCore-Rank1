/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:29 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:06:48 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Determines if char is alphanumeric.
/// @param c Integer representing an ASCII value.
/// @return Returns 1 if it's alphanumeric. Otherwise, returns 0.
int	ft_isalnum(int c)
{
	if ((c - 'A' <= 25 && c - 'A' >= 0) || (c - 'a' <= 25 && c - 'a' >= 0))
		return (1);
	else if (c - '0' < 10 && c - '0' >= 0)
		return (1);
	else
		return (0);
}
