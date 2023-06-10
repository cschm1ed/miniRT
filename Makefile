

VPATH			:= sources

BUILDDIR		:= build

LIBFT 			:= libft.a

LIBFTDIR		:= libft

CFLAGS			:= -Wall -Werror -Wextra -O2 -march=native -I ./includes -I ./libft

LDFLAGS			:= $(CFLAGS) -fsanitize=address

SRCS			:= main.c

OBJS			:= $(SRCS:%.c=$(BUILDDIR)/%.o)

NAME			:= minirt

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFT)
	$(CC) $(LDFLAGS) $^ $(LIBFTDIR)/$(LIBFT) -o $(NAME)

$(OBJS): $(SRCS) $(BUILDDIR)
	${CC} $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(LIBFTDIR)/$(LIBFT):
	@make -C $(LIBFTDIR)

all: $(NAME)

clean:
	@$(RM) -rf $(BUILDDIR)
	@$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
