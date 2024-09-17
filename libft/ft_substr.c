/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:58:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 21:30:26 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Find a substring in a string that starts on element number 'start' and is 'len' bytes long.
/// @param s String to search in.
/// @param start Starting element of the substring.
/// @param len Size of the substring.
/// @return Pointer to the new string.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*str;
	size_t	total_len;

	if (!s)
		return (NULL);
	str = (char *) s + start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(str) < len)
		total_len = ft_strlen(str);
	else
		total_len = len;
	ret = malloc((total_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, total_len + 1);
	return (ret);
}
