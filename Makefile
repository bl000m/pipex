# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:44:01 by mpagani           #+#    #+#              #
#    Updated: 2023/01/10 17:08:04 by mpagani          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex
# NAME_BONUS 	= pipex_bonus

# mandatory srcs / obj files
SRCS 		= main.c \
			memory_stuff.c \
			parsing.c \
			communicating.c \
			settings.c \
			error_management.c \
			utils.c

OBJS 		= $(SRCS:%.c=$(OBJDIR)/%.o)

# bonus srcs / obj files
BONUS_SRCS	= main_bonus.c \
			memory_stuff_bonus.c \
			parsing_bonus.c \
			communicating_bonus.c \
			settings_bonus.c \
			error_management_bonus.c \
			utils_bonus.c

OBJS_BONUS	= $(BONUS_SRCS:%.c=$(OBJ_BON_DIR)/%.o)

# compile
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra

# directories
SRCS_DIR	= ./srcs
BONUS_DIR	= ./bonus
INCS_DIR	= ./includes
OBJDIR 		= ./obj
OBJ_BON_DIR = ./obj_bonus

# library ft_
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_INC	= -I ./libft
LIBFT_LNK	= -L ./libft -l ft

# others
RM 			= rm -rf

all: obj $(LIBFT) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT_LNK) -lm -o $(NAME)

$(OBJDIR)/%.o: $(SRCS_DIR)/%.c Makefile $(INCS_DIR)/pipex.h
	$(CC) $(CFLAGS) $(LIBFT_INC) -I $(INCS_DIR) -c $< -o $@

bonus: obj_bonus $(LIBFT) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIBFT_LNK) -lm -o $(NAME)

$(OBJ_BON_DIR)/%.o: $(BONUS_DIR)/%.c Makefile $(INCS_DIR)/pipex_bonus.h
	$(CC) $(CFLAGS) $(LIBFT_INC) -I $(INCS_DIR) -c $< -o $@

obj_bonus:
	mkdir -p $(OBJ_BON_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJDIR)
	$(RM) $(OBJ_BON_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re

