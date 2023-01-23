/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:40:13 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/16 17:22:32 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(int argc, char *argv[], t_pipe *data)
{

  if (argc != 6)
		exit(1);
	getting_and_writing_input_on_file(argv[2]);
	data->file_in = open(".here_doc", O_RDONLY);
	if (data->file_in < 0)
		error_manager(6, NULL, data);
	if (dup2(data->file_in, STDIN_FILENO) < 0)
		error_manager(6, NULL, data);
}

void	getting_and_writing_input_on_file(char *limiter)
{
	int		limiter_size;
	char	*input;
	int		fd;

	fd = open(".here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	limiter_size = ft_strlen(limiter);
	while (1)
	{
		ft_printf("pipex here_doc> ");
		input = get_next_line(STDIN_FILENO);
		if (!input)
		{
			close(fd);
			exit(1);
		}
		if (input[limiter_size] == '\n' && limiter
			&& (ft_strncmp(input, limiter, limiter_size) == 0))
		{
			close(fd);
			break ;
		}
		ft_putstr_fd(input, fd);
		free(input);
		input = NULL;
	}
	free(input);
	close(fd);
}
