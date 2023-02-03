/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:36:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/24 14:43:31 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*data;

	check_error(argc);
	data = init_data(argc);
	opening_files(data, argv);
	parsing_environment(data, envp);
	communicating(data, argv, envp);
}

void	communicating(t_pipe *data, char *argv[], char *envp[])
{
	creating_pipe(data);
	creating_sending_child(data, 2);
	data->pos = 2;
	if (data->sending_child == 0)
		child_process(data, argv, envp, 's');
	creating_receiving_child(data, 7);
	data->pos++;
	if (data->receiving_child == 0)
		child_process(data, argv, envp, 'r');
	closing_input_output(data);
	exit_clean(data);
	waiting_childs_finishing(data);
}

void	child_process(t_pipe *data, char *argv[], char *envp[], char flag)
{
	matching_commands_with_right_path(data, argv, data->pos);
	switching_input_output(data, flag);
	closing_input_output(data);
	if (data->file_in > 0)
		executing_command(data, envp);
}
