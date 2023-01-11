/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:40:13 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/11 12:16:08 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(int argc, char *argv[])
{
	if (argc != 6)
		exit(1);
	if (pipe(data->here_pipe) == -1)
		error_manager(1, argv, data);
	data->here_doc_child = fork();
	if (data->here_doc_child == -1)
		error_manager(2, argv, data);
	if (data->here_doc_child == 0)
		getting_and_sending_input(argv[2], data);
}

void	getting_and_sending_input(char *limiter, t_pipe *data)
{
	int	limiter_size;
	char *input;

	limiter_size = ft_strlen(limiter);
	line = get_next_line(STDIN_FILENO);
	if (!line)
	{
		closing_input_output(data, 'h')
		exit(1)
	}
	if (line[limiter_size] == '\n' && limiter && !ft_strncmp(line, limiter, limiter_size))
	{
		closing_input_output(data, 'h');
		// exit(0);
	}
	ft_putstr_fd(line, data->here_pipe[1]);
	free(line);
	line = NULL;
}