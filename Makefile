# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 22:55:36 by estruckm          #+#    #+#              #
#    Updated: 2023/06/18 20:00:30 by estruckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRCS =	main.c \
		init.c \
		string_utils1.c \
		parsing.c \
		interpret_scene.c

VPATH	:= sources:sources/parsing:sources/utils
CC = gcc
CCFLAG = -Wall -Werror -Wextra -g
# -fsanitize=address
#-g -fprofile-instr-generate -fcoverage-mapping
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB = -C ./libft
GET = -C ./Get_next_line/

SUCCESS_COLOR = \033[32m

OBJECT = $(SRCS:.c=.o)
D_SRCS = ./srcs/

all : $(NAME)

%.o:$(D_SRCS)%.c
	$(CC) $(CCFLAG) -o $@ -c $<

$(NAME) : $(OBJECT)
	make $(LIB)
	make $(GET)
	$(CC) $(CCFLAG) $(MLXFLAGS)  $(OBJECT) ./Get_next_line/get_next_line_bonus.a ./libft/libft.a -o $(NAME)
	echo "$(SUCCESS_COLOR)$(NAME) - Compiled with Success"

clean :
	@make clean $(LIB)
	@make clean $(GET)
	@echo "$(SUCCESS_COLOR)$(NAME) - Cleaned with Success"
	@/bin/rm -rf $(OBJECT)

fclean : clean
	@make fclean $(LIB)
	@make fclean $(GET)
	@rm -rf ./$(NAME)
	@echo "$(SUCCESS_COLOR)$(NAME) - FCleaned with Success"

re : fclean all

.PHONY: all clean fclean re

compile:
	make re
	make clean

#Get_next_line/get_next_line_bonus.a
