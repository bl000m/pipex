/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communicating.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:13:53 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/10 16:57:46 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	communicating(t_pipe *data, char *argv[], char *envp[])
{
	creating_pipe(data);
	creating_sending_child(data, 2);
	if (data->sending_child == 0)
		sending_process(data, argv, envp);
	creating_receiving_child(data, 7);
	if (data->receiving_child == 0)
		receiving_process(data, argv, envp);
	closing_input_output(data, 'p');
	waiting_childs_finishing(data);
	exit_clean(data, 'p');
}

void	sending_process(t_pipe *data, char *argv[], char *envp[])
{
	matching_commands_with_right_path(data, argv, 2);
	switching_input_output(data, 's');
	closing_input_output(data, 's');
	executing_command(data, envp);
}

void	receiving_process(t_pipe *data, char *argv[], char *envp[])
{
	matching_commands_with_right_path(data, argv, 3);
	switching_input_output(data, 'r');
	closing_input_output(data, 'r');
	executing_command(data, envp);
}
