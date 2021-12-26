/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:13:27 by cvenkman          #+#    #+#             */
/*   Updated: 2021/12/26 21:04:18 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"

# define STD_ERR 2
# define STD_OUT 1

# define BUFFER_SIZE 10
# define SPEED		0.132
# define ROT_SPEED	0.05

# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define ESC	53
# define KEY_ARR_L	123
# define KEY_ARR_R	124

# define SCREEN_W	1920
# define SCREEN_H	1080

# define TEX_WIDTH	128
# define TEX_HEIGHT	128

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_point	size_img;
}				t_win;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				side;
	int				draw_start;
	int				line_height;
	int				draw_end;
	double			step;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				tex_x;
	double			wall_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			tex_pos;
	struct s_data	*data;
}				t_player;

typedef struct s_texture
{
	int	n;
	int	s;
	int	w;
	int	e;
	int	**north;
	int	**south;
	int	**west;
	int	**east;
}				t_texture;

typedef struct s_data
{
	char		*way_to_file_so;
	char		*way_to_file_no;
	char		*way_to_file_we;
	char		*way_to_file_ea;
	char		*fl;
	char		*cl;
	int			floor[3];
	int			ceil[3];
	int			f;
	int			c;
	char		player_dir;
	int			player_pos[2];
	char		**map;
	t_win		*win;
	t_player	*player;
	t_texture	*texture;
	int			map_h;
}				t_data;

/* parser functions */
int		get_next_line(int fd, char **line);
int		map_check(int argc, char **argv);
void	check_map_in(char **map, int y, int x);
void	check_map_player(char **map, int y, int x, t_data *data);
void	parse_map(char **map, t_data *data);
char	**list_to_map(t_list **map_list, int size, t_data *data, int k);
char	*remove_space(char	*str);
int		str_is_empty(char *str);
char	*list_to_string(char *content);
void	ft_lst_free(t_list **lst);
void	init_data(t_data *data);
void	fill_data_f(t_data *data, char *content, int i);
void	fill_data_c(t_data *data, char *content, int i);
void	fill_data(t_data *data, char *content);
void	fill_data_so(t_data *data, char *content, int i);
void	fill_data_no(t_data *data, char *content, int i);
void	fill_data_we(t_data *data, char *content, int i);
void	fill_data_ea(t_data *data, char *content, int i);
int		color_help2(char c1, char c2);
void	color_help(char	*str);
void	color_free(t_data *data, char **str, int k);
void	parse_color_ceil(t_data *data);
void	parse_color(t_data *data);
void	first_errors(int k);
void	type_error(void);
void	malloc_error(void);
void	map_error(void);
void	color_error(void);

// src/mini_map.c
void	mini_map_draw(t_data *data);

// keys.c
int		key(int keycode, t_player *player);

// raycast.c
void	start_raycasting(t_data *data);
void	raycasting(t_player *player);

// keys_wasd.c
void	key_w(t_player *player);
void	key_a(t_player *player);
void	key_s(t_player *player);
void	key_d(t_player *player);

// compass_points.c
void	init_we(t_data *data);

// draw_verline.c
void	draw_verline(t_win *info, int x, int y_start, t_data *data);

// textures.c
void	init_texture(t_data *data);

// lodev's_calculations.c
void	line_start_and_end(t_player *player);
void	step_and_side_dist(t_player *player);
void	dda(t_player *player);
void	ft_perp_wall_dist(t_player *player);
void	for_textures(t_player *player);

#endif