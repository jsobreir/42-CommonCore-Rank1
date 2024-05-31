/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:06:36 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/28 19:29:03 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	*handle_signal_print()
{
	
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", (int)pid);
	
	while (1)
	{
		signal(SIGINT1, handle_signal_print);
	}
}