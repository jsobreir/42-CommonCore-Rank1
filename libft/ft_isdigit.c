/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:48 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:07:53 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Determines if char is a digit.
/// @param c Integer representing an ASCII value.
/// @return Returns 1 if it's a digit. Otherwise, returns 0.
int	ft_isdigit(int c)
{
	if (c - '0' < 10 && c - '0' >= 0)
	{
		return (1);
	}
	else
		return (0);
}

// int	main(void)
// {
// 	char c = 'f';
// 	char d = 'A';
// 	// char f = 'Z';
// 	// char z = 'z';

// 	printf("%d", ft_isdigit(c));
// 	printf("%d", ft_isdigit(d));
// 	printf("%d", ft_isdigit('0'));
// 	printf("%d", ft_isdigit('9'));
// 	printf("%d", ft_isdigit());
// }