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
# include <stdbool.h>
# include "mlx/mlx.h"

# define PINK 0x00F000F0
# define RED 0x00FF0000
# define BLACK 0x00000000

// # define KEY_W 0
// # define KEY_A 13
// # define KEY_S 2
// # define KEY_D 1
// # define ESC 53

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC 53

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

# define KEY_ARR_L		123
# define KEY_ARR_R		124

typedef struct	s_win //структура для окна
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				  t_win;

typedef struct	s_player //структура для окна
{
	double	x;
	double	y;
	bool W;
	bool A;
	bool S;
	bool D;
	double dir;
	double start;
	double end;
	double	dir_x;
	double	dir_y;
	double plane_x;
	double plane_y;
	double move_speed;
	struct 	s_data *data;
}				  t_player;

typedef	struct 	s_data
{
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
	char	*fl;//vremenno - ne uzat posle pars
	char	*cl;//vremenno -  ne uzat posle pars
	int		floor[3];
	int		ceil[3];
	char	player_dir;
	int		player_pos[2];
	char	**map;
	t_win	*win;
	t_player *player;
	int map_h;
}				t_data;


int		map_check(int	argc,char **argv);
int		get_next_line(int fd, char **line);
int		str_is_empty(char *str);
char	**list_to_map(t_list **map_list, int size, t_data *data);
void	fill_data(t_data *data, char *content);
void	parse_map(char **map, t_data *data);
void	ft_lst_free(t_list **lst);
void	check_map_in(char **map, int y, int x);
void	malloc_error();

// src/mini_map.c
void mini_map_draw(t_data *data);
void	my_mlx_pixel_put(t_win *window, int x, int y, int color, int ajaraguju);

void nazvanie_pridumayu_potom(t_data *data);
#endif