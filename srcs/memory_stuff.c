/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:03:25 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/07 17:54:00 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_error(int argc)
{
	if (argc != 5)
		exit(1);
}

int	check_fd_error(int fd)
{
	if (fd == -1 || read(fd, 0, 0) < 0)
		exit (1);
	return (1);
}

void	error_manager(int errno)
{
	if (errno == 2)
		ft_printf("Error opening file_input\n");
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
