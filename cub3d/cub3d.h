#ifndef	CUB3D_H
# define CUB3D_H

# define STD_ERR 2
# define STD_OUT 1
# define BUFFER_SIZE 10

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <sys/errno.h>
# include "mlx/mlx.h"

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
}				  t_win;

typedef struct	s_all // структура для всего вместе
{
	t_win		*window;
	char		**map;
}				  t_all;

int		map_check(int	argc,char **argv);
int		get_next_line(int fd, char **line);
int		str_is_empty(char *str);
char	**list_to_map(t_list **map_list, int size);


#endif