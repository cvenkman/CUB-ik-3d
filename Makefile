NAME = cub3d

SRCS =	main.c \
		parser/map_check.c parser/colors.c parser/errors.c \
		parser/fill_data.c parser/fill_data_2.c \
		parser/parse_utils.c parser/get_next_line.c \
		lodev/lodevs_calculations.c\
		lodev/raycast.c lodev/keys.c lodev/compass_points.c \
		lodev/draw_verline.c lodev/keys_wasd.c lodev/init_textures.c
 
SRCS_PATH = srcs/

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FT = -L libft -lft

MLX_FLAGS = -lmlx -framework Opengl -framework Appkit

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(FT) -g

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C mlx
	make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx
	make -C libft/ fclean

re: fclean all