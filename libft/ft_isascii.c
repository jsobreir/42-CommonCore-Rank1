/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:42 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:07:38 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Determines if char is in ASCII table.
/// @param c Integer representing an ASCII value.
/// @return Returns 1 if it's in ASCII. Otherwise, returns 0.
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(void)
// {
// 	char c = 'f';
// 	char d = 'A';
// 	// char f = 'Z';
// 	// char z = 'z';

// 	printf("%d", ft_isascii(c));
// 	printf("%d", ft_isascii(d));
// 	printf("%d", ft_isascii(' '));
// 	printf("%d", ft_isascii(2));
// }