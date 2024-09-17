/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:09:18 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:39:15 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates space to join two strings and then joins the strings.
/// @param s1 String to join.
/// @param s2 String to join.
/// @return Pointer to the first element of the first string.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy (ret, s1, len1 + 1);
	ft_strlcpy (ret + len1, s2, len2 + 1);
	return (ret);
}
