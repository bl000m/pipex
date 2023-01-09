/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:37:55 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/09 12:43:20 by mpagani          ###   ########lyon.fr   */
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
	char	*dir_command;
	pid_t	sending_child;
	pid_t	receiving_child;
	int		pipe[2];
	char	**commands;
}	t_pipe;

/* settings */
t_pipe	*init_data(int argc);

/* parsing */
void	opening_files(t_pipe *data, char *argv[]);
void	parsing_environment(t_pipe *data, char *argv[]);
char	*searching_path(char *envp[]);
char	*find_dir_command(t_pipe *data);

/* communicating */
void	communicating(t_pipe *data, char *argv[], char *envp[]);
void	sending_process(t_pipe *data, char *argv[], char *envp[]);
void	receiving_process(t_pipe *data, char *argv[], char *envp[]);

/* memory stuff */
void	closing_pipes(t_pipe *data);
void	waiting_childs_finishing(t_pipe *data);
void	close_fd(int *pipes[], int i);

/* checking for error */
void	error_manager(int error);
int		check_fd_error(int fd);
void	check_error(int argc);



#endif
