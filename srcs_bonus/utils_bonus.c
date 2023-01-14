/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:38:14 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/13 17:51:26 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	executing_command(t_pipe *data, char *envp[], char *argv[])
{
	if (execve(data->dir_command, data->commands, envp) == -1)
		error_manager(3, argv, data);
}

void	creating_pipe(t_pipe *data, char *argv[])
{
	if (pipe(data->pipe) == -1)
		error_manager(1, argv, data);

}

void	creating_child(char *argv[], t_pipe *data, int err)
{
	data->child = fork();
	if (data->child == -1)
		error_manager(err, argv, data);
}

