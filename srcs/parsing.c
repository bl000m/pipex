/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:54:22 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/06 18:33:44 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//to verify if to give permission to FILE_OUT
void	opening_files(t_pipe *data, char *argv[])
{
	data->file_in = open(argv[1], O_RDONLY);
	if (data->file_in == -1)
		error_manager(2);
	data->file_out = open(argv[4], O_WRONLY);
	if (data->file_out == -1)
		error_manager(2);
}

void	parsing_instructions(t_pipe *data, char *envp[])
{
	// int	i;

	// i = 0;

	data->path = searching_path(envp);
}

char *searching_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] && (ft_strnstr(envp[i], "PATH=", 5) == 0))
	{
		i++;
	}
	if (envp[i] == NULL)
		error_manager(3);
	return (envp[i]);
}
