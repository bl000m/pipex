/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:43:22 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/11 10:49:53 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

t_pipe	*init_data(int argc)
{
	t_pipe *data;

	data = malloc(sizeof(*data));
	if (!data)
	{
		ft_printf("ERROR ALLOCATING DATA: %s\n", strerror(errno));
		exit(1);
	}
	data->argc = argc;
	data->n_cmd = argc - 3;
	return (data);
}
