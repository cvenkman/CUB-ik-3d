NAME = cub3d

SRCS =	main.c \
		map_check.c \
		get_next_line.c

SRCS_PATH = srcs/

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall

FT = -L libft -lft

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT)

clean:
	$(RM) $(OBJS)
	make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all