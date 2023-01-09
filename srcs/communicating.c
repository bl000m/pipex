/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communicating.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:13:53 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/09 13:10:49 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	communicating(t_pipe *data, char *argv[], char *envp[])
{
	if (pipe(data->pipe) == -1)
		error_manager(5);
	data->sending_child = fork();
	if (data->sending_child == -1)
		error_manager(6);
	if (data->sending_child == 0)
		sending_process(data, argv, envp);
	data->receiving_child = fork();
	if (data->receiving_child == -1)
		error_manager(7);
	if (data->receiving_child == 0)
		receiving_process(data, argv, envp);
	closing_pipes(data);
	waiting_childs_finishing(data);
}

void	sending_process(t_pipe *data, char *argv[], char *envp[])
{
	data->commands = ft_split(argv[2], ' ');
	// ft_printf("data->commands = %s\n", data->commands[0]);
	data->dir_command = find_dir_command(data);
	if (!data->dir_command)
		error_manager(8);
	// ft_printf("data->dir_command = %s\n", data->dir_command);
	dup2(data->pipe[1], STDOUT_FILENO);
	close(data->pipe[0]);
	dup2(data->file_in, STDIN_FILENO);
	close(data->file_in);
	close(data->pipe[1]);
	if (execve(data->dir_command, data->commands, envp) == -1)
		error_manager(9);
	//free child if fail
}

void	receiving_process(t_pipe *data, char *argv[], char *envp[])
{
	dup2(data->pipe[0], STDIN_FILENO);
	dup2(data->file_out, STDOUT_FILENO);
	if (!dup2(data->file_out, STDOUT_FILENO))
		error_manager(10);
	close(data->pipe[0]);
	close(data->file_out);
	close(data->pipe[1]);
	data->commands = ft_split(argv[3], ' ');
	data->dir_command = find_dir_command(data);
	if (!data->dir_command)
		error_manager(8);
	if (execve(data->dir_command, data->commands, envp) == -1)
		error_manager(9);
	//free child if fail
}
