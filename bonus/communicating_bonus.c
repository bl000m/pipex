/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communicating_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:13:53 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/13 13:08:17 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	communicating(t_pipe *data, char *argv[], char *envp[])
{
	while (data->pos < data->argc - 2)
	{
		// if (data->pipe[1] == 0)
		creating_pipe(data, argv);
		creating_child(argv, data, 2);
		if (data->child == 0)
			sending_process(data, argv, envp);
		if (dup2(data->pipe[0], STDIN_FILENO) < 0)
			ft_printf("ERROR in switching fd in parent\n");
		closing_input_output(data);
		waitpid(-1, NULL, WNOHANG);
		data->pos++;
	}
	if (dup2(data->file_out, STDOUT_FILENO) < 0)
			ft_printf("ERROR in switching fd in OUT receiving\n");
	closing_input_output(data);
	wait(NULL);
	matching_commands_with_right_path(data, argv, data->argc - 2);
	// exit_clean(data, 'p');
	executing_command(data, envp, argv);
	// waiting_childs_finishing(data);
	//free_pipes
}

void	sending_process(t_pipe *data, char *argv[], char *envp[])
{
	if (data->file_in < 0)
	{
		closing_input_output(data);
		exit(1);
	}
	ft_printf("here\n");
	if (dup2(data->pipe[1], STDOUT_FILENO) < 0)
			ft_printf("ERROR in switching fd in sending_process\n");
	closing_input_output(data);
	matching_commands_with_right_path(data, argv, data->pos);
	executing_command(data, envp, argv);
}

