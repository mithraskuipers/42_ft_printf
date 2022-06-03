SRC = ./ft_printf/ft_printf.c \
	./ft_printf/fs_c.c \
	./ft_printf/fs_di.c \
	./ft_printf/fs_p.c \
	./ft_printf/fs_s.c \
	./ft_printf/fs_u.c \
	./ft_printf/fs_x.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
		@$(MAKE) -C $(LIBFT_PATH)
		@ar rcs $(NAME) $(OBJ) $(LIBFT_PATH)/*.o

%.o: %.c
		gcc -Wall -Werror -Wextra -c $< -o $@

clean:
		@$(MAKE) clean -C $(LIBFT_PATH)
		@rm -rf $(OBJ)

fclean: clean
		@$(MAKE) fclean -C $(LIBFT_PATH)
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
