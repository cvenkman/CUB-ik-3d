#include "../cub3d.h"
static void init_mlx(t_win *window);
static void init_texture(t_data *data);
void static	get_color_texure(t_data *data, int ***color, char *way_to_file);
void		error_exit(char *str);
void		parse(t_data *data, int argc, char **argv);
static void	delete_n_in_map_and_find_player(t_data *data, char **map);
void		init_mlx_and_textures(t_data *data);

int	main(int argc, char **argv)
{
	t_data data;

	parse(&data, argc, argv);
	init_WE(&data);
	init_mlx_and_textures(&data);
	data.player->data = &data;
	// data.player->temp_value = malloc(sizeof(t_tmp_value) * 1);
	// printf("%f %f\n", data.player->data->player->x, data.player->data->player->y);

	// mini_map_draw(&data);
	// int r = 255;
	// int g = 255;
	// int b = 0;
	// // хуйню строчкой ниже нужно куда-нибудь засунуть
	data.f = (data.floor[2] << 16) + (data.floor[1] << 8) + data.floor[0];
	data.c = (data.ceil[2] << 16) + (data.ceil[1] << 8) + data.ceil[0];
	// // int color = (r << 16) + (g << 8) + b;
	start_raycasting(&data);
	// mlx_loop(data.win->mlx);
	return (0);
}

void parse(t_data *data, int argc, char **argv)
{
	int	fd;
	char	*cur_str;
	t_list	*map_list;
	char	**map;

	cur_str = NULL;
	map_list = NULL;
	ft_bzero(data, sizeof(t_data));
	fd = map_check(argc, argv);
	while (get_next_line(fd, &cur_str))
		if (!str_is_empty(cur_str) || ft_lstsize(map_list) > 6)
			ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	close(fd);
	data->win = malloc(sizeof(t_win) * 1);
	data->player = malloc(sizeof(t_player) * 1);
	data->texture = malloc(sizeof(t_texture) * 1);
	ft_bzero(data->texture, sizeof(t_texture));
	map = list_to_map(&map_list, ft_lstsize(map_list), data);
	delete_n_in_map_and_find_player(data, map);
}

static void delete_n_in_map_and_find_player(t_data *data, char **map)
{
	//убираю N в карте и записываю координаты игрока
	int j;
	int i;

	i = -1;
	data->map = malloc(sizeof(char *) * (data->map_h + 1));
	while (map[++i])
	{
		j = 0;
		data->map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				data->player->y = j + 0.5;
				data->player->x = i + 0.5;
				data->map[i][j] = '0';
			}
			else
				data->map[i][j] = map[i][j];
			j++;
		}
		data->map[i][j] = '\0';
	}
	data->map[i] = NULL;
}

void init_mlx_and_textures(t_data *data)
{
	init_mlx(data->win);
	data->win->size_img.x = SCREEN_W;
	data->win->size_img.y = SCREEN_H;
	init_texture(data);
}

static void init_mlx(t_win *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, SCREEN_W, SCREEN_H, "CUBik");
	if (!window->win)
		exit(EXIT_FAILURE);
	window->img = mlx_new_image(window->mlx, SCREEN_W, SCREEN_H);
	if (!window->img)
		exit(EXIT_FAILURE);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
				&window->line_length, &window->endian);
}

unsigned int get_pixel_color(t_win *img, int i, int j)
{
	char			*adr;
	unsigned int	color;

	adr = img->addr + (j * img->line_length + i * (img->bits_per_pixel / 8));
	color = *(unsigned int *)adr;
	return (color);
}

void	init_texture(t_data *data)
{
	get_color_texure(data, &data->texture->north, data->way_to_file_no);
	get_color_texure(data, &data->texture->south, data->way_to_file_so);
	get_color_texure(data, &data->texture->west, data->way_to_file_we);
	get_color_texure(data, &data->texture->east, data->way_to_file_ea);
}

void static	get_color_texure(t_data *data, int ***color, char *way_to_file)
{
	int		width;
	int		h;
	int		i;
	int		j;
	t_win	img;

	i = -1;
	img.img = mlx_xpm_file_to_image(data->win->mlx, way_to_file, &width, &h);
	if (!img.img)
		error_exit("img error with textures");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
						&img.line_length, &img.endian);
	(*color) = malloc(sizeof(int *) * width);
	if (!(*color))
		error_exit("malloc error with color");
	while (++i < TEX_WIDTH)
	{
		j = -1;
		(*color)[i] = malloc(sizeof(int) * h);
		while (++j < TEX_HEIGHT)
			(*color)[i][j] = get_pixel_color(&img, i, j);
	}
}
void error_exit(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}
