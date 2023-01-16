/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:55:27 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/16 16:29:53 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	check_error(int argc)
{
	if (argc < 5)
	{
		ft_printf("n. of argument incorrected\n");
		exit(1);
	}
}

void	error_manager(int error, char *argv[], t_pipe *data)
{
	if (error == 1)
		ft_printf("ERROR CREATING PIPE: %s\n", strerror(errno));
	else if (error == 2)
		ft_printf("ERROR CREATING PROCESS: %s\n", strerror(errno));
	else if (error == 3)
	{
		ft_printf("command or directory path's command not found: %s, %s\n",
			argv[2], strerror(errno));
		exit_clean(data, 'f');
	}
	else if (error == 4)
		ft_printf("ENV PATH not set: %s\n", strerror(errno));
	else if (error == 5)
	{
		if (data->file_in)
			close(data->file_in);
		ft_printf("OUTPUT ERROR: %s => %s\n",
			strerror(errno), argv[data->argc - 1]);
	}
	else if (error == 6)
		ft_printf("ERROR in switching fd: %s\n", strerror(errno));
	exit(1);
}
