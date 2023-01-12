/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:37:55 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/12 14:45:13 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"
# include "errno.h"
# include "string.h"

# define PROCESS_N 2

typedef struct s_pipe
{
	int		argc;
	int		file_in;
	int		file_out;
	char	*path;
	char	**path_dir;
	char	**commands;
	char	*dir_command;
	pid_t	sending_child;
	pid_t	receiving_child;
	int		pipe[2];
}	t_pipe;

/* settings */
t_pipe	*init_data(int argc);

/* parsing */
void	opening_files(t_pipe *data, char *argv[]);
void	parsing_environment(t_pipe *data, char *envp[], char *argv[]);
char	*searching_path(char *envp[]);
char	*find_dir_command(t_pipe *data);

/* communicating */
void	communicating(t_pipe *data, char *argv[], char *envp[]);
void	creating_pipe(t_pipe *data, char *argv[]);
void	creating_sending_child(char *argv[], t_pipe *data, int err);
void	creating_receiving_child(char *argv[], t_pipe *data, int err);
void	sending_process(t_pipe *data, char *argv[], char *envp[]);
void	receiving_process(t_pipe *data, char *argv[], char *envp[]);

/* utils */
void	matching_commands_with_right_path(t_pipe *data, char *argv[], int pos);
void	switching_input_output(t_pipe *data, char *flag);
void	executing_command(t_pipe *data, char *envp[], char *argv[]);

/* error management */
void	error_manager(int error, char *argv[], t_pipe *data);
void	check_error(int argc);

/* memory stuff */
void	closing_input_output(t_pipe *data, char *flag);
void	waiting_childs_finishing(t_pipe *data);
void	free_path_dir(t_pipe *data);
void	free_commands(t_pipe *data);
void	exit_clean(t_pipe *data, char c);

#endif
