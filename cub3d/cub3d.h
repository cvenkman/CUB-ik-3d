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

typedef	struct 	s_data
{
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
	char	*fl;//vremenno
	char	*c;//vremenno
	int		floor[3];
	int		ceil[3];
	char	player_pos;
}				t_data;


int		map_check(int	argc,char **argv);
int		get_next_line(int fd, char **line);
int		str_is_empty(char *str);
char	**list_to_map(t_list **map_list, int size, t_data *data);
void	fill_data(t_data *data, char *content);
void	parse_map(char **map);
void	ft_lst_free(t_list **lst);




#endif