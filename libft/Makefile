# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 22:21:59 by cschmied          #+#    #+#              #
#    Updated: 2023/04/22 10:51:32 by cschmied         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH			:=  sources:ft_printf:get_next_line/sources

SRCS_BONUS		:=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			 		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			 		ft_lstmap.c

OBJS_BONUS 		:= $(SRCS_BONUS:.c=.o)

SRCS_GNL		:= get_next_line.c get_next_line_utils.c

SRCS := 			ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcmp.c 	\
    				ft_memmove.c ft_strchr.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c \
					ft_toupper.c ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memchr.c 	\
					ft_memcpy.c ft_memset.c ft_strlcat.c ft_strlen.c ft_strnstr.c 	\
					ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c	\
					ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c	 \
					ft_putstr_fd.c ft_putendl_fd.c ft_split.c ft_putnbr_fd.c ft_printf.c \
					print_char.c print_decimal.c print_hexpointer.c print_itohex_lower.c \
					print_itohex_upper.c print_string.c print_unsignedi.c $(SRCS_GNL)

OBJS 				:= $(SRCS:.c=.o)

NAME 				:= libft.a

CC 					:= cc

AR 					:= ar rcs

CFLAGS 				:= -Wall -Werror -Wextra -O2

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus

all: $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus:	$(NAME) $(OBJS) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

