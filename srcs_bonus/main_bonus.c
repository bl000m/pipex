/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:36:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/16 17:51:37 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int main(int argc, char *argv[], char *envp[])
{
	t_pipe	*data;

	check_error(argc);
	data = init_data(argc);
	parsing_environment(data, envp, argv);
  if (argv[1] && (ft_strncmp(argv[1], "here_doc", 8) == 0)
		&& argv[1][8] == '\0')
    checking_here_doc(argc, argv, data);
  else
		multiple_commands_handling(argc, argv, data);
	communicating(data, argv, envp);
  // while(1){}
	return (0);
}

void	checking_here_doc(int argc, char *argv[], t_pipe *data)
{
	// if (argv[1] && (ft_strncmp(argv[1], "here_doc", 8) == 0)
	// 	&& argv[1][8] == '\0')
	// {
		data->pos = 3;
		data->n_cmd = 2;
		data->here_doc = 1;
		here_doc(argc, argv, data);
		opening_files(data, argv, 'h');
		// return (1);
	// }
	// return (0);
}

void	multiple_commands_handling(int argc, char *argv[], t_pipe *data)
{
	data->pos = 2;
	data->n_cmd = argc - 3;
	data->here_doc = 0;
	opening_files(data, argv, 's');
	if (dup2(data->file_in, STDIN_FILENO) < 0)
		error_manager(6, argv, data);
}
