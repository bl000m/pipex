/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:03:25 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/06 17:52:52 by mpagani          ###   ########lyon.fr   */
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
		ft_printf("Error opening file_input");
}

// void	pipes_error_manager(int errno, int *pipes[], int i)
// {
// 	if (errno == 1)
// 	{
// 		ft_printf("Error (1) creating pipes\n");
// 		close_fd(pipes, i);
// 	}
// 	else if (errno == 2)
// 	{
// 		ft_printf("Error (2) creating processes\n");
// 		close_fd(pipes, i);
// 	}
// 	exit(1);
// }

void	close_fd(int *pipes[], int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
	}
}

void	waiting_childs_finishing(int pid_1, int pid_2)
{
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
}
