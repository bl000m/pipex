/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communicating_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:13:53 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/16 17:59:47 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	communicating(t_pipe *data, char *argv[], char *envp[])
{
	creating_pipe(data, argv);
	while (data->pos <= data->argc - 2)
	{
	  creating_pipe(data, argv);
		creating_child(argv, data, 2);
		if (data->child == 0)
      child_process(data, argv, envp);
		if (dup2(data->pipe[0], STDIN_FILENO) < 0)
			error_manager(6, argv, data);
		closing_input_output(data);
		data->pos++;
	}
	closing_input_output(data);
	close(data->file_in);
	close(data->file_out);
	exit_clean(data, 'p');
	while (waitpid(-1, NULL, 0) > 0)
		;
}

void	child_process(t_pipe *data, char *argv[], char *envp[])
{
	if (data->file_in < 0)
	{
		closing_input_output(data);
		exit(1);
	}
  if (data->pos == data->argc - 2)
	{
    ft_printf("pos = %d\n", data->pos);
		if (dup2(data->file_out, STDOUT_FILENO) < 0)
		  error_manager(6, argv, data);
    close(data->file_out);
	}
  else
	{
		if (dup2(data->pipe[1], STDOUT_FILENO) < 0)
			error_manager(6, argv, data);
	}
	closing_input_output(data);
	if (data->file_in != 0)
	{
		matching_commands_with_right_path(data, argv, data->pos);
		executing_command(data, envp, argv);
	}
}
