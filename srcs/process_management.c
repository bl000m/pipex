/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:43:00 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/06 17:47:18 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	creating_pipes(int *pipes)
// {
// 	int	i;

// 	i = 0;
// 	while (i < PROCESS_N + 1)
// 	{
// 		if (pipe(&pipes[i]) == -1)
// 			pipes_error_manager(1, &pipes, i);
// 		ft_printf("pipe %d created\n", i);
// 		i++;
// 	}
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
