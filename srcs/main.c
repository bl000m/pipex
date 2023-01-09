/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:36:33 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/09 13:10:16 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_pipe *data;

	check_error(argc);
	data = init_data(argc);
	opening_files(data, argv);
	parsing_environment(data, envp);
	communicating(data, argv, envp);
	exit(1);
}
