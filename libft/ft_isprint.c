/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:55 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:08:07 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Determines if char is printable.
/// @param c Integer representing an ASCII value.
/// @return Returns 1 if it's a printable value. Otherwise, returns 0.
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int main(void)
// {
// 	printf("%d", ft_isprint('c'));
// 	printf("%d", ft_isprint(127));
// 	printf("%d", ft_isprint(0));
// }