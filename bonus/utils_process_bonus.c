/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:19 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/12 17:33:23 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

// void	creating_pipes(char *argv[], t_pipe *data)
// {
// 	int	i;
// 	int	fd[2];

// 	i = 0;
	// *data->pipes = malloc(sizeof(*data->pipes) * (data->n_cmd - 1));
// 	ft_printf("n. commands = %d\n", data->n_cmd);
// 	while (i < data->n_cmd - 1)
// 	{
// 		ft_printf("in the while\n");
// 		ft_printf("i = %d\n", i);
// 		if (pipe(fd[i++]) == -1)
// 			error_manager(1, argv, data);
// 		ft_printf("here\n");
// 	}
// 	*data->pipes = *fd;
// }

// void	creating_processes(int *pids, int *pipes)
// {
// 	int	i;

// 	i = 0;
// 	while (i < PROCESS_N)
// 	{
// 		pids[i] = fork();
// 		if (pids[i] < 0)
// 			pipes_error_manager(2, &pipes, i);
// 		i++;
// 	}
// }
