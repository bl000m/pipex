/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:36:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/14 18:24:47 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int main(int argc, char *argv[], char *envp[])
{
	t_pipe	*data;
	// int	i;

	check_error(argc);
	data = init_data(argc);
	parsing_environment(data, envp, argv);
	if (!checking_here_doc(argc, argv, data))
		multiple_pipes_handling(argc, argv, data);
	communicating(data, argv, envp);
	// while (1)
	// 	i = 0;
	return(0);
}

int	checking_here_doc(int argc, char *argv[], t_pipe *data)
{
	if (argv[1] && (ft_strncmp(argv[1], "here_doc", 8) == 0)
		&& argv[1][8] == '\0')
	{
		data->pos = 3;
		data->n_cmd = 2;
		data->here_doc = 1;
		here_doc(argc, argv, data);
		opening_files(data, argv, 'h');
		return (1);
	}
	return (0);
}

void	multiple_pipes_handling(int argc, char *argv[], t_pipe *data)
{
	data->pos = 2;
	data->n_cmd = argc - 3;
	data->here_doc = 0;
	opening_files(data, argv, 's');
	if (dup2(data->file_in, STDIN_FILENO) < 0)
		ft_printf("ERROR in switching fd in receiving\n");
}
