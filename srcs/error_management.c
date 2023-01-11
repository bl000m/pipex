/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:55:27 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/10 17:30:46 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	exit(1);
}
