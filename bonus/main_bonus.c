/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:36:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/13 12:55:49 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int main(int argc, char *argv[], char *envp[])
{
	t_pipe	*data;

	check_error(argc);
	data = init_data(argc);
	if (argv[1] && (ft_strncmp(argv[1], "here_doc", 8) == 0)
		&& argv[1][8] == '\0')
	{
		ft_printf("I'm in here_doc case\n");
		data->pos = 3;
		data->n_cmd = 2;
		here_doc(argc, argv, data);
		opening_files(data, argv, 'h');
	}
	else
	{
		ft_printf("I'm in standard case\n");
		ft_printf("data->pipe[1] before creating pipe = %d\n", data->pipe[1]);
		data->pos = 2;
		data->n_cmd = argc - 3;
		opening_files(data, argv, 's');
		if (dup2(data->file_in, STDIN_FILENO) < 0)
			ft_printf("ERROR in switching fd in receiving\n");
	}
	parsing_environment(data, envp, argv);
	communicating(data, argv, envp);
}
