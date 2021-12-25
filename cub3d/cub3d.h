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
#include <math.h>

// #define w screenWidth
// #define h screenHeight

#define SPEED 0.15
#define ROT_SPEED 0.05 // SPEED / 3.0


# define PINK 0x00F000F0
# define RED 0x00FF0000
# define BLACK 0x00000000

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC 53

#define SCREEN_W 640
#define SCREEN_H 480
#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#define TEX_WIDTH 64
#define TEX_HEIGHT 64

# define KEY_ARR_L		123
# define KEY_ARR_R		124
typedef struct s_point
{
	int		x;
	int		y;
}	t_point;
typedef struct	s_win //структура для окна
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_point size_img;
	// int		size_img_x;
	// int		size_img_y;
}				  t_win;

// typedef struct s_tmp_value
// {
// 	// int step_x;
// 	// int step_y;
// 	// double side_dist_x;
// 	// double side_dist_y;
// 	// int map_x;
// 	// int map_y;
// }				t_tmp_value;


typedef struct	s_player //структура для окна
{
	double	x;
	double	y;
	// double dir;
	// double start;
	// double end;
	double	dir_x;
	double	dir_y;
	double plane_x;
	double plane_y;
	int side;
	int		draw_start;
	int line_height;
	int		draw_end;
	double	step;
	int step_x;
	int step_y;
	double side_dist_x;
	double side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		tex_x;
	double	wall_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int map_x;
	int map_y;
	double	tex_pos;
	// double move_speed;
	struct 	s_data *data;
	// t_tmp_value *temp_value;
}				  t_player;


typedef struct s_texture
{
	int		n;
	int		s;
	int		w;
	int		e;
	int		**north;
	int		**south;
	int		**west;
	int		**east;
	// char	*no;
	// char	*so;
	// char	*we;
	// char	*ea;
}	t_texture;


typedef	struct 	s_data
{
	char	*way_to_file_so;
	char	*way_to_file_no;
	char	*way_to_file_we;
	char	*way_to_file_ea;
	char	*fl;//vremenno - ne uzat posle pars
	char	*cl;//vremenno -  ne uzat posle pars
	int		floor[3];
	int		ceil[3];
	char	player_dir;
	int		player_pos[2];
	char	**map;
	t_win	*win;
	t_player *player;
	t_texture *texture;
	t_win				img_map;
	int	map_h;
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

// keys.c
int	key(int keycode, t_player *player);

// raycast.c
void start_raycasting(t_data *data);
int raycasting(t_player *player);
// keys_wasd.c
void key_w(t_player *player);
void key_a(t_player *player);
void key_s(t_player *player);
void key_d(t_player *player);

// compass_points.c
void init_WE(t_data *data);

// draw_verline.c
void	draw_verLine(t_win *info, int x, int y_start, int y_end, t_data *data, int color);
#endif