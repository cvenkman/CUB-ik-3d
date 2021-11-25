NAME = cub3d

SRCS =	main.c \
		map_check.c \
		get_next_line.c

SRCS_PATH = srcs/

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall

FT = -L libft -lft

MLX_FLAGS = -lmlx -framework Opengl -framework Appkit

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C mlx
	make -C libft/
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(FT)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C mlx
	make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx
	make -C libft/ fclean

re: fclean all