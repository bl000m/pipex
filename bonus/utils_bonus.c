/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:38:14 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/13 11:54:17 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

// void	switching_input_output(t_pipe *data, char flag)
// {
// 	if (flag == 's')
// 	{
// 		if (dup2(data->pipe[0][1], STDOUT_FILENO) < 1)
// 			ft_printf("ERROR in switching fd in sending OUT\n");
// 		if (dup2(data->file_in, STDIN_FILENO) < 0)
// 			ft_printf("ERROR in switching fd in sending IN\n");
// 	}
// 	if (flag == 'r')
// 	{
// 		if (dup2(data->pipe[1][0], STDIN_FILENO) < 0)
// 			ft_printf("ERROR in switching fd in receiving\n");
// 		if (dup2(data->file_out, STDOUT_FILENO) < 0)
// 			ft_printf("ERROR in switching fd in OUT receiving\n");
// 	}
// 	if (flag == 'm')
// 	{
// 		ft_printf("IN THE SENDING MULTIPLE SWITCHING\n");
// 		ft_printf("data->pos = %d\n", data->pos);
// 		if (dup2(data->pipe[1][0], STDIN_FILENO) < 0)
// 			ft_printf("ERROR in switching fd in receiving\n");
// 		if (dup2(data->pipe[0][1], STDOUT_FILENO) < 0)
// 			ft_printf("ERROR in switching fd in receiving\n");
// 	}
// 	if (flag == 'n')
// 	{
// 		ft_printf("IN THE RECEIVING MULTIPLE SWITCHING\n");
// 		ft_printf("data->pos = %d\n", data->pos);
// 		if (data->pos )
// 		if (dup2(data->pipe[0][0], STDIN_FILENO) < 0)
// 			ft_printf("ERROR in switching fd in receiving\n");
// 		if (dup2(data->pipe[1][1], STDOUT_FILENO) < 0)
// 			ft_printf("ERROR in switching fd in receiving\n");
// 	}
// }

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

// void	creating_receiving_child(char *argv[], t_pipe *data, int err)
// {
// 	data->receiving_child = fork();
// 	if (data->receiving_child == -1)
// 		error_manager(err, argv, data);
// }
