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
		parsing.c \
		interpret_scene.c

VPATH	:= sources:sources/parsing:sources/utils
CC = gcc
CCFLAG = -Wall -Werror -Wextra -g
# -fsanitize=address
#-g -fprofile-instr-generate -fcoverage-mapping
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB = ./libft

MAKE	:= make

SUCCESS_COLOR = \033[32m

OBJECT = $(SRCS:.c=.o)

all : $(NAME)

%.o:%.c
	$(CC) $(CCFLAG) -o $@ -c $<

$(NAME) : $(OBJECT)
	$(MAKE) -C $(LIB)
	$(CC) $(CCFLAG) $(MLXFLAGS) $(OBJECT) ./libft/libft.a -o $(NAME)
	echo "$(SUCCESS_COLOR) $(NAME) - Compiled with Success"

.PHONY: all clean fclean re compile

clean :
	@$(MAKE) -C $(LIB) clean
	@echo "$(SUCCESS_COLOR) $(NAME) - Cleaned with Success"
	@rm -rf $(OBJECT)

fclean : clean
	@$(MAKE) -C $(LIB) fclean
	@rm -rf ./$(NAME)
	@echo "$(SUCCESS_COLOR) $(NAME) - FCleaned with Success"

re : fclean all

compile:
	make re
	make clean

#Get_next_line/get_next_line_bonus.a
