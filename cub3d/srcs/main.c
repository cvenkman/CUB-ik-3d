#include "../cub3d.h"

void ft_mlx(t_win *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 600, 300, "cub3d");
}

// void mini_map_draw(t_all *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < )

// }

int	main(int argc, char **argv)
{
	int	fd;
	char	*cur_str;
	t_list	*map_list;
	t_all	*data;

	cur_str = NULL;
	map_list = NULL;
	data = malloc(sizeof(t_all) * 1);
	data->window = malloc(sizeof(t_win) * 1);
	if (!data || !data->window)
		exit(EXIT_FAILURE);
	fd = map_check(argc, argv);
	while (get_next_line(fd, &cur_str))
		if (!str_is_empty(cur_str) || ft_lstsize(map_list) > 6)
			ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	close(fd);
	data->map = list_to_map(&map_list, ft_lstsize(map_list)); //получился двумерный массив
	ft_mlx(data->window);
	// mini_map_draw(data);
	// int i = 0;
	// while (data->map[i])
	// 	printf("%s\n", data->map[i++]);

	mlx_loop(data->window->mlx);
	return (0);
}
