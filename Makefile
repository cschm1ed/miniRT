# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 22:55:36 by estruckm          #+#    #+#              #
#    Updated: 2023/07/29 13:09:13 by estruckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= miniRT
SRCS 			:= main.c \
				   init.c \
				   parsing.c \
				   interpret_scene_1.c \
				   interpret_scene_2.c \
				   free_stuff.c \
				   put_pixel.c \
				   trgb.c \
				   slice_utils1.c \
				   parsing_check_utils.c \
				   dot_product.c \
				   cross_product.c \
				   vector_len.c \
				   vector_add.c \
				   vector_subtract.c \
				   vector_scalar.c \
				   angles_to_vector.c \
				   vector_multiply.c \
				   parallel_vector_check.c \
				   line_sphere.c \
				   line_plane.c \
				   line_triangle.c \
				   key_events.c \
				   trace_ray.c \
				   angle_between_vectors.c \
				   rad_to_deg.c \
				   colour_to_vector.c \
				   pow_vector.c \
				   sqrt_vector.c \
				   render_scene.c \
				   no_event.c \
				   shading.c \
				   line_cylinder2.c \
				   line_cone.c \
				   surface_normal_cylinder.c \
				   get_colour.c \
				   check_map.c \
				   check_map_object_1.c \
				   check_map_object_2.c \

VPATH			:= sources:\
					sources/parsing:\
					sources/utils:\
					sources/mlx_utils:\
					sources/intersections\
					sources/quick_maths:\
					sources/tracing

BUILDDIR		:= build

CC 				:= gcc
CCFLAG 			:= -Wall -Werror -Wextra -g
#-march=native -Ofast
# -fsanitize=address
#-g -fprofile-instr-generate -fcoverage-mapping

MLXFLAGS 		:= -I /usr/X11/include -L ./minilibx_macos -L /usr/X11/lib -lX11 \
                   			-lmlx -lXext -lm -framework OpenGL -framework AppKit
LIB 			:= ./libft

MAKE			:= make

SUCCESS_COLOR 	:= \033[32m

OBJECT 			:= $(SRCS:%.c=$(BUILDDIR)/%.o)


$(NAME) : $(OBJECT)
	$(MAKE) -C $(LIB)
	$(CC) $(CCFLAG) $(MLXFLAGS) $(OBJECT) ./libft/libft.a -o $(NAME)
	echo "$(SUCCESS_COLOR) $(NAME) - Compiled with Success"

$(BUILDDIR)/%.o:%.c $(BUILDDIR)
	$(CC) $(CCFLAG) -o $@ -c $<

$(BUILDDIR):
	@mkdir $(BUILDDIR)

.PHONY: all clean fclean re compile

clean :
	@$(MAKE) -C $(LIB) clean
	@echo "$(SUCCESS_COLOR) $(NAME) - Cleaned with Success"
	@rm -rf $(OBJECT)
	@rm -rf $(BUILDDIR)

fclean : clean
	@$(MAKE) -C $(LIB) fclean
	@rm -rf ./$(NAME)
	@echo "$(SUCCESS_COLOR) $(NAME) - FCleaned with Success"

all: $(NAME)

re : fclean all

compile:
	make re
	make clean

#Get_next_line/get_next_line_bonus.a
