/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:36:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/06 18:05:25 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

// int	pipes[PROCESS_N + 1][2];
// int	pids[PROCESS_N];
	// creating_pipes(*pipes);
	// creating_processes(pids, *pipes);
int main(int argc, char *argv[], char *envp[])
{
	t_pipe *data;

	data = init_data();
	check_error(argc);
	opening_files(data, argv);
	parsing_instructions(data, envp);
}


// int	main(int argc, char *argv[])
// {
// 	int	file_in;
// 	int	file_out;
// 	int	fd[2];
// 	int	pid_1;
// 	int	pid_2;
// 	char *str;
// 	char **commands;
// 	// char *argv_2[] = {"/sbin/ping", "google.com", "-c", "5", NULL};
// 	int val;

// 	if (argc < 2)
// 		exit(1);
// 	str = dup_command_line(argv);
// 	*commands = ft_split(str, ' ');
// 	file_in = open(argv[1], O_RDONLY);
// 	check_fd_error(file_in);
// 	if (pipe(fd) == -1)
// 		return (1);
// 	pid_1 = fork();
// 	if (pid_1 == -1)
// 		return (2);
// 	ft_printf("Before child loop\n");
// 	if (pid_1 == 0)
// 	{
// 		ft_printf("In child loop\n");
// 		dup2(file_in, STDIN_FILENO);
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		close(file_in);
// 		ft_printf("I've all closed\n");
// 		val = execve(commands[0], commands, NULL);
// 		if (val == -1)
// 			return (1);
// 		//split commands
// 	}
// 	pid_2 = fork();
// 	if (pid_2 == 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		dup2(file_out, STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[0]);
// 		execlp("grep", "grep", "round-trip", NULL);
// 		//where to write ? stdout calling execve with commands?
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	waiting_childs_finishing(pid_1, pid_2);
// 	return (0);
// }
