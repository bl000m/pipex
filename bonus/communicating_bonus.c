/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communicating_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:13:53 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/10 17:51:19 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	communicating(t_pipe *data, char *argv[], char *envp[])
{

	creating_pipe(data, argv);
	data->pos = 2;
	while (data->pos < data->argc - 1)
	{
		creating_sending_child(argv, data, 2);
		if (data->sending_child == 0)
			sending_process(data, argv, envp);
		data->pos++;
	}
	while (data->pos < data->argc - 1)
	{
		creating_receiving_child(argv, data, 7);
		if (data->receiving_child == 0)
			receiving_process(data, argv, envp);
		data->pos++;
	}
	closing_input_output(data, 'p');
	waiting_childs_finishing(data);
	exit_clean(data, 'p');
}

void	sending_process(t_pipe *data, char *argv[], char *envp[])
{
	switching_input_output(data, 's');
	closing_input_output(data, 's');
	if (data->file_in != 0)
	{
		matching_commands_with_right_path(data, argv, data->pos);
		executing_command(data, envp, argv);
	}
}

void	receiving_process(t_pipe *data, char *argv[], char *envp[])
{
	switching_input_output(data, 'r');
	closing_input_output(data, 'r');
	matching_commands_with_right_path(data, argv, data->pos);
	executing_command(data, envp, argv);
}
