/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_stuff_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:03:25 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/13 12:16:32 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

// s == sending || r == receiving || p == parent
void	closing_input_output(t_pipe *data)
{
	close(data->pipe[0]);
	close(data->pipe[1]);
}

void	free_path_dir(t_pipe *data)
{
	int	i;

	i = 0;
	if (data->path_dir)
	{
		while (data->path_dir[i])
		{
			free(data->path_dir[i]);
			data->path_dir[i] = NULL;
			i++;
		}
		free(data->path_dir);
		data->path_dir = NULL;
	}
}

void	free_commands(t_pipe *data)
{
	int	i;

	i = 0;
	if (data->commands)
	{
		while (data->commands[i])
		{
			free(data->commands[i]);
			i++;
		}
		free(data->commands);
	}
}

//TO BE CHECKED if char *dir_command and char *path need to be NULL pointed
//f == fail | c == child | p == parent
void	exit_clean(t_pipe *data, char c)
{
	if (c == 'f' || c == 'c')
		free_commands(data);
	if (c == 'f' || c == 'p')
		free(data);
		// free_path_dir(data);
	// if (data->dir_command)
	// 	free(data->dir_command);
	// if (data->path)
	// 	free(data->path);
}
