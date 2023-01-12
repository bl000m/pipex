/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communicating_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:13:53 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/12 17:52:38 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	communicating(t_pipe *data, char *argv[], char *envp[])
{
	// if (data->pipe[1] == 0)
	creating_pipe(data, argv);
	while (data->pos <= data->argc - 2)
	{
		creating_sending_child(argv, data, 2);
		if (data->sending_child == 0)
			sending_process(data, argv, envp);
		data->pos++;
		creating_receiving_child(argv, data, 2);
		if (data->receiving_child == 0)
			receiving_process(data, argv, envp);
		data->pos++;
	}
	closing_input_output(data, 'p');
	wait(NULL);
	// waiting_childs_finishing(data);
	//free_pipes
	exit_clean(data, 'p');
}

void	sending_process(t_pipe *data, char *argv[], char *envp[])
{
	if (data->pos == 2)
	{
		switching_input_output(data, 's');
		closing_input_output(data, 's');
	}
	else
	{
		switching_input_output(data, 'm');
		closing_input_output(data, 'm');
	}
	if (data->file_in != 0)
	{
		matching_commands_with_right_path(data, argv, data->pos);
		executing_command(data, envp, argv);
	}
}

void	receiving_process(t_pipe *data, char *argv[], char *envp[])
{
	if (data->pos == data->argc - 2)
	{
		ft_printf("IN receiving LAST ARG\n");
		switching_input_output(data, 'r');
		closing_input_output(data, 'r');
	}
	else
	{
		ft_printf("IN receiving MIDDLE ARG\n");
		switching_input_output(data, 'n');
		closing_input_output(data, 'n');
	}
	matching_commands_with_right_path(data, argv, data->pos);
	executing_command(data, envp, argv);
}
