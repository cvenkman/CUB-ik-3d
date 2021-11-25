#include "../cub3d.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*cur_str;
	t_list	*map_list;
	char	**map;

	cur_str = NULL;
	map_list = NULL;
	fd = map_check(argc, argv);
	while (get_next_line(fd, &cur_str))
		if (!str_is_empty(cur_str) || ft_lstsize(map_list) > 6)
			ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	close(fd);
	map = list_to_map(&map_list, ft_lstsize(map_list));//получился двумерный массив
	return (0);
}
