#include "../cub3d.h"

void ft_mlx(t_win *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 600, 300, "cub3d");
	// window->img = mlx_new_image(window->mlx, 100, 30);
	// window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel, &window->line_length,
	// 							&window->endian);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*cur_str;
	t_list	*map_list;
	char	**map;
	t_data	data;

	cur_str = NULL;
	map_list = NULL;
	fd = map_check(argc, argv);
	while (get_next_line(fd, &cur_str))
		if (!str_is_empty(cur_str) || ft_lstsize(map_list) > 6)
			ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	close(fd);
	data.map = list_to_map(&map_list, ft_lstsize(map_list), &data);//получился двумерный массив и в дате все текстуры
	
	data.win = malloc(sizeof(t_win) * 1);
	data.player = malloc(sizeof(t_player) * 1);
	ft_mlx(data.win);
	mini_map_draw(&data);
	int r = 120;
	int g = 44;
	int b = 1;
	// хуйню строчкой ниже нужно куда-нибудь засунуть
	int color = (data.floor[2] << 16) + (data.floor[1] << 8) + data.floor[0];
	int color2 = (data.ceil[2] << 16) + (data.ceil[1] << 8) + data.ceil[0];
	printf("!!! %d %d\n", color, color2);
	// nazvanie_pridumayu_potom(&data);
	mlx_loop(data.win->mlx);
	return (0);
}
