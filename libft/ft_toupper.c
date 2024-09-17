/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:45:57 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 21:32:04 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts an alphabetic character to uppercase, if lowercase. Ignores all non-alphabetic.
/// @param c Char to convert.
/// @return Converted char.
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

// int main(void)
// {
// 	printf("%c", ft_toupper('c'));
// 	printf("%c", ft_toupper(30));
// }