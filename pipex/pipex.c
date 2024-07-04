/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:42:29 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/03 17:30:57 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile "command_1" "command_2" outfile 
int	main(int argc, char **argv)
{
	
	// init_pipex();
	
	// check_args();
	if (argc < 5)
		parse_err();
	// parse_cmds();
	char	**commands;
	
	commands[0] = argv[2];
	commands[1] = argv[3];
	// parse_args();
	int	fd[2];
	int	pid;
	char	**files;
	
	files[0] = argv[1];
	files[1] = argv[4];
	
	// ft_exec();
	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		// Child process
		dup2(fd[1], STDOUT_FILENO);
		execve(path, commands, NULL);
	}
	else
	{
		close(fd[1]);
		dup2(fd);
	}
		
		
	// cleanup();
}