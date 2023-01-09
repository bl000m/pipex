/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:03:25 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/09 12:42:45 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_error(int argc)
{
	if (argc != 5)
	{
		ft_printf("n. of argument incorrected\n");
		exit(1);
	}
}

int	check_fd_error(int fd)
{
	if (fd == -1 || read(fd, 0, 0) < 0)
		exit (1);
	return (1);
}

void	error_manager(int error)
{
	if (error == 2)
		ft_printf("Error opening file_input\n");
	if (error == 3)
		ft_printf("Error opening file_output\n");
	else if (error == 4)
		ft_printf("ENV PATH not set\n");
	exit(1);
}

void	closing_pipes(t_pipe *data)
{
	close(data->pipe[0]);
	close(data->pipe[1]);
}

void	waiting_childs_finishing(t_pipe *data)
{
	waitpid(data->sending_child, NULL, 0);
	waitpid(data->receiving_child, NULL, 0);
}
