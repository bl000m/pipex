/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:37:31 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/27 13:59:16 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl
{
	char			*content;
	struct s_list	*next;
}	t_gnl;

char	*get_next_line(int fd);
int		check_eol(t_list *stash);
void	ft_add_pattern(t_list **lst, char *buffer, int characters);
int		ft_line_size(t_list *record);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(const char *str);
void	read_stock(t_list **record, int fd);
void	compose_line(char **line, t_list *record);
void	clean_record(t_list **record);
void	ft_free_list(t_list *record);

#endif
