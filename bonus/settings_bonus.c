/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:43:22 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/10 17:11:52 by mpagani          ###   ########lyon.fr   */
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
	return (data);
}
