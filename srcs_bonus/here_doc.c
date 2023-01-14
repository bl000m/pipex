/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:40:13 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/14 18:13:36 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(int argc, char *argv[], t_pipe *data)
{
	if (argc != 6)
		exit(1);
	creating_pipe(data, argv);
	creating_child(argv, data, 2);
	if (data->child == 0)
		child_getting_and_writing_input_on_pipe(argv[2], data);
	else
		parent_switching_stdin_with_pipe(data);
}

void	child_getting_and_writing_input_on_pipe(char *limiter, t_pipe *data)
{
	int		limiter_size;
	char	*input;

	limiter_size = ft_strlen(limiter);
	while (1)
	{
		ft_printf("pipex here_doc> ");
		input = get_next_line(STDIN_FILENO);
		if (!input)
		{
			closing_input_output(data);
			exit(1);
		}
		if (input[limiter_size] == '\n' && limiter
			&& (ft_strncmp(input, limiter, limiter_size) == 0))
		{
			closing_input_output(data);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(input, data->pipe[1]);
		free(input);
		input = NULL;
	}
}

void	parent_switching_stdin_with_pipe(t_pipe *data)
{
	if (dup2(data->pipe[0], STDIN_FILENO) < 0)
		ft_printf("ERROR in switching fd in receiving\n");
	closing_input_output(data);
	waitpid(data->child, NULL, 0);
}
