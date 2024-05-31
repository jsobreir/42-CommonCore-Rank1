/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:03:52 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/28 19:28:11 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_send_signal(int pid, int sig)
{
	kill(pid, sig);
}

int	main(int argc, char **argv)
{
	int	server_pid;
	
	server_pid = ft_atoi(argv[1]);
	
	if (argc == 3)
	{
		signal(server_pid, ft_send_signal())
	}
}