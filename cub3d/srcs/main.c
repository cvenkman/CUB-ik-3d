#include "../cub3d.h"

void ft_mlx(t_win *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, screenWidth, screenHeight, "cub3d");
	window->img = mlx_new_image(window->mlx, screenWidth, screenHeight);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel, &window->line_length,
								&window->endian);
}

// char worldMap[mapWidth][mapHeight]=
// {
//   {"111111111111111111111111"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000222220000303030001"},
//   {"100000200020000000000001"},
//   {"100000200020000300030001"},
//   {"100000200020000000000001"},
//   {"100000220220000303030001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"144444444000000000000001"},
//   {"140400004000000000000001"},
//   {"140000504000000000000001"},
//   {"140400004000000000000001"},
//   {"140444444000000000000001"},
//   {"140000000000000000000001"},
//   {"144444444000000000000001"},
//   {"111111111111111111111111"}
// };

int	main(int argc, char **argv)
{
	int	fd;
	char	*cur_str;
	t_list	*map_list;
	char	**map;
	t_data	data;

	cur_str = NULL;
	map_list = NULL;
	ft_bzero(&data, sizeof(t_data));
	fd = map_check(argc, argv);
	while (get_next_line(fd, &cur_str))
		if (!str_is_empty(cur_str) || ft_lstsize(map_list) > 6)
			ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	close(fd);
data.win = malloc(sizeof(t_win) * 1);
data.player = malloc(sizeof(t_player) * 1);
	map = list_to_map(&map_list, ft_lstsize(map_list), &data);//получился двумерный массив и в дате все текстуры
	int i = 0;

	//убираю N в карте и записываю координаты игрока
	data.map = malloc(sizeof(char *) * (data.map_h + 1));
	i = 0;
	int j;
	while (map[i])
	{
		j = 0;
		data.map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				data.player->y = j + 0.5;
				data.player->x = i + 0.5;
				data.map[i][j] = '0';
			}
			else
				data.map[i][j] = map[i][j];
			j++;
		}
		data.map[i][j] = '\0';
		i++;
	}
	data.map[i] = NULL;
	// int u = 0;
	// int a = 0;
	// while (data.map[u])
	// {
	// 	a = 0;
	// 	while (data.map[u][a])
	// 	{
	// 		if (data.map[u][a] == 'N')
	// 		{
	// 			data.player->x = a + 0.5;
	// 			data.player->y = u + 0.5;
	// 		}
	// 		a++;
	// 	}
	// 	u++;
	// }
	// data.player->x = 19 + 0.5;
	// data.player->y = 18 + 0.5;
	data.player->data = &data;
	printf("%f %f\n", data.player->data->player->x, data.player->data->player->y);
	// i = 0;
	// while (data.map[i])
	// {
	// 	printf("%s\n", data.map[i]);
	// 	i++;
	// }
	// printf("%f %f\n", data.player->x, data.player->y);
	ft_mlx(data.win);
	// mini_map_draw(&data);
	// int r = 255;
	// int g = 255;
	// int b = 0;
	// // хуйню строчкой ниже нужно куда-нибудь засунуть
	// // int color = (data.floor[2] << 16) + (data.floor[1] << 8) + data.floor[0];
	// // int color2 = (data.ceil[2] << 16) + (data.ceil[1] << 8) + data.ceil[0];
	// // int color = (r << 16) + (g << 8) + b;

	nazvanie_pridumayu_potom(&data);
	// mlx_loop(data.win->mlx);
	return (0);
}
