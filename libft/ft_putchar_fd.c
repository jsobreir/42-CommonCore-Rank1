/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:04:51 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/17 14:32:58 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Puts a char to a certain file descriptor.
/// @param c Char to put.
/// @param fd File Descriptor.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}
