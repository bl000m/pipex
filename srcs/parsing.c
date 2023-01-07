/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:54:22 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/07 18:08:09 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//to verify if to give permission to FILE_OUT
void	opening_files(t_pipe *data, char *argv[])
{
	data->file_in = open(argv[1], O_RDONLY);
	if (data->file_in == -1)
		error_manager(2);
	data->file_out = open(argv[4], O_CREAT| O_RDWR | O_TRUNC, 0000644);
	if (data->file_out == -1)
		error_manager(2);
}

void	parsing_environment(t_pipe *data, char *envp[])
{
	data->path = searching_path(envp);
	if (!data->path)
		error_manager(3);
	else
		data->path_dir = ft_split(data->path, ':');
	ft_printf("path = %s\n", data->path);
}

char	*searching_path(char *envp[])
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	if (envp[i] == NULL)
		error_manager(3);
	return (envp[i] + 5);
}

	// find in data->path_dir the one that execute data->commands[0]
	// considering for themoment just 1 command
char	*find_dir_command(t_pipe *data)
{
	int		i;
	char	*path_dir;
	char	*path_with_command;

	i = 0;
	//to be verifies if other to check before-> cfr inspiration
	while (data->path_dir[i])
	{
		path_dir = ft_strjoin(data->path_dir[i], "/");
		path_with_command = ft_strjoin(path_dir, data->commands[0]);
		if (access(path_with_command, F_OK | X_OK) == 0)
			return (path_with_command);
		free(path_with_command);
		free(path_dir);
		i++;
	}
	return (NULL);
}
