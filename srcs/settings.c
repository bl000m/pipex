/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:43:22 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/06 18:04:41 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipe	*init_data(void)
{
	t_pipe *data;

	data = malloc(sizeof(*data));
	if (!data)
		error_manager(3);
	return (data);
}
