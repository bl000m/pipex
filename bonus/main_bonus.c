/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:36:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/11 12:21:21 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int main(int argc, char *argv[], char *envp[])
{
	t_pipe *data;

	check_error(argc);
	data = init_data(argc);
	if (argv[1] && (ft_strncmp(argv[1], "here_doc", 8) == 0) && argv[1][8] == '\0')
	{
		data->pos = 3;
		here_doc(argc, argv);
		opening_files(data, argv, 'h');
	}
	else
	{
		data->pos = 2;
		opening_files(data, argv, 's');
	}
	parsing_environment(data, envp, argv);
	communicating(data, argv, envp);
}
