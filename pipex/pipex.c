/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:42:29 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/04 20:13:16 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

// ./pipex infile "command_1" "command_2" outfile 
int	main(int argc, char **argv)
{
	t_args	args;
	
	init();
	parse_files();
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dprintf(STDOUT_FILENO, "r");
		close(fd[0]);
	}
	else
	{
		char	buffer[1];
		
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		read(STDIN_FILENO, buffer, 1);
		write(STDOUT_FILENO, buffer, 1);
	}
}