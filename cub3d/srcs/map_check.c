#include "../cub3d.h"

int		map_check(int	argc, char **argv)
{
	int	size;
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Arguments Error\n", STD_ERR);
		exit(0);
	}
	size = ft_strlen(argv[1]);
	if (size < 4 || (ft_strncmp(argv[1] + size - 4, ".cub", 4) != 0))
	{
		ft_putstr_fd("Invalid map format!\n", STD_ERR);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("No such file or directory\n", STD_ERR);
		exit(0);
	}
	return (fd);
}

int		str_is_empty(char *str)
{
	if (str[0] == '\0')
	{
		free(str);
		return (1);
	}
	return (0);
}

char	*list_to_string(char *content)
{
	char	*str;

	str = ft_strdup(content);
	if (!str)
		malloc_error();
	return (str);
}

void	fill_data(t_data *data, char *content)
{
	int	i;

	i = 0;
	while (content[i] == ' ')
			i++;
	if (content[i] == 'S' && content[i + 1] == 'O' && content[i + 2] == ' ')
	{
		i += 2;
		while (content[i] == ' ')
			i++;
		data->so = ft_strdup((content + i));
	}
	else if (content[i] == 'N' && content[i + 1] == 'O' && content[i + 2] == ' ')
	{
		i += 2;
		while (content[i] == ' ')
			i++;
		data->no = ft_strdup((content + i));
	}
	else if (content[i] == 'W' && content[i + 1] == 'E' && content[i + 2] == ' ')
	{
		i += 2;
		while (content[i] == ' ')
			i++;
		data->we = ft_strdup((content + i));
	}
	else if (content[i] == 'E' && content[i + 1] == 'A' && content[i + 2] == ' ')
	{
		i += 2;
		while (content[i] == ' ')
			i++;
		data->ea = ft_strdup((content + i));
	}
	else if (content[i] == 'F' && content[i + 1] == ' ')
	{
		i++;
		while (content[i] == ' ')
			i++;
		data->fl = ft_strdup((content + i));
	}
	else if (content[i] == 'C' && content[i + 1] == ' ')
	{
		i++;
		while (content[i] == ' ')
			i++;
		data->cl = ft_strdup((content + i));
	}
	else
	{
		ft_putstr_fd("Type identifier error\n", STD_ERR);
		exit(0);
	}
}

void	ft_lst_free(t_list **lst)
{
	t_list	*tmp;
	t_list	*beg;

	tmp = *lst;
	while (tmp->next)
	{
		beg = tmp;
		tmp = tmp->next;
		if (beg->content != NULL)
			free(beg->content);
		free(beg);
	}
	if (tmp->content != NULL)
		free(tmp->content);
	free(tmp);
	*lst = NULL;
}

void	malloc_error()
{
	ft_putstr_fd("Malloc error\n", STD_ERR);
	exit(0);
}

void	map_error()
{
	ft_putstr_fd("Map error\n", STD_ERR);
	exit(0);
}

void	color_error()
{
	ft_putstr_fd("Colour error\n", STD_ERR);
	exit(0);
}

void	check_map_in(char **map, int y, int x)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (y == 0 || x == 0 || x == ft_strlen(map[y]) - 1 || y == i - 1)
		map_error();
	else if (x >= ft_strlen(map[y - 1]) || x >= ft_strlen(map[y + 1]))
		map_error();
	else if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' ||
			map[y][x + 1] == ' ' || map[y][x - 1] == ' ')
		map_error();
}

void	check_map_player(char **map, int y, int x, t_data *data)
{
	data->player_pos[0] = y;
	data->player_pos[1] = x;
	if (data->player_dir != '0')
		map_error();
	data->player_dir = map[y][x];
}

void	parse_map(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][0] == '\0')
			map_error();
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
			&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
				map_error();
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
			|| map[i][j] == 'W')
				check_map_in(map, i, j);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				check_map_player(map, i, j, data);
			j++;
		}
		i++;
	}
	if 	(data->player_pos[0] == 0 || data->player_pos[1] == 0)
		map_error();
}

char	*remove_space(char	*str)
{
	int	i;
	int	k;
	char	*tmp;

	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] != ' ')
			k++;
	tmp = (char *)malloc(sizeof(char) * (k + 1));
	if (!tmp)
		malloc_error();
	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] != ' ')
		{
			tmp[k] = str[i];
			k++;
		}
	tmp[k] = '\0';
	free(str);
	return (tmp);
}

int		color_help2(char c1, char c2)
{
	if (ft_isdigit(c1) && (c2 == ' ' || c2 == ',' || c2 == '\0'))
		return (1);
	return (0);
}

void	color_help(char	*str)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (str[++i] != ',')
		k += color_help2(str[i], str[i + 1]);
	if (k != 1)
		color_error();
	while (str[++i] != ',')
		k += color_help2(str[i], str[i + 1]);	
	if (k != 2)
		color_error();
	i++;
	while (str[i])
	{
		k += color_help2(str[i], str[i + 1]);	
		i++;
	}
	if (k != 3)
		color_error();
}

void	color_free(t_data *data, char **str, int k)
{
	if (ft_atoi(str[0]) > 255 || ft_atoi(str[1]) > 255 || ft_atoi(str[2]) > 255)
		color_error();
	if (k == 1)
	{
		data->floor[0] = ft_atoi(str[0]);
		data->floor[1] = ft_atoi(str[1]);
		data->floor[2] = ft_atoi(str[2]);
		free(data->fl);
	}
	else
	{
		data->ceil[0] = ft_atoi(str[0]);
		data->ceil[1] = ft_atoi(str[1]);
		data->ceil[2] = ft_atoi(str[2]);
		free(data->cl);
	}
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str);
}

void	parse_color_ceil(t_data *data)
{
	int	i;
	int	z;
	char	**tmp;

	i = 0;
	z = 0;
	while (data->cl[i])
	{
		if (data->cl[i] != ',' && data->cl[i] != ' ' && (data->cl[i] < '0' || data->cl[i] > '9'))
			color_error();
		if (data->cl[i] == ',')
			z++;
		i++;
	}
	if (z != 2)
		color_error();
	color_help(data->cl);
	data->cl = remove_space(data->cl);
	tmp = ft_split(data->cl, ',');
	if (!tmp)
		malloc_error();
	color_free(data, tmp, 0);
}

void	parse_color(t_data *data)
{
	int	i;
	int	z;
	char	**tmp;

	i = 0;
	z = 0;
	while (data->fl[i])
	{
		if (data->fl[i] != ',' && data->fl[i] != ' ' && (data->fl[i] < '0' || data->fl[i] > '9'))
			color_error();
		if (data->fl[i] == ',')
			z++;
		i++;
	}
	if (z != 2)
		color_error();
	color_help(data->fl);
	data->fl = remove_space(data->fl);
	tmp = ft_split(data->fl, ',');
	if (!tmp)
		malloc_error();
	color_free(data, tmp, 1);
	parse_color_ceil(data);
}

char	**list_to_map(t_list **map_list, int size, t_data *data)
{
	char	**map;
	int	i;
	t_list	*tmp;
	int	k;

	map = (char **)malloc(sizeof(char *) * (size + 1 - 6));
	if (!map)
		malloc_error();
	tmp = *map_list;
	i = 0;
	k = 0;
	while (tmp)
	{
		if (k <= 5)
			fill_data(data, tmp->content);
		if (k > 5)
		{
			map[i] = list_to_string(tmp->content);
			data->map_h++;
			i++;
		}
		tmp = tmp->next;
		k++;
	}
	map[i] = NULL;
	ft_lst_free(map_list);
	data->player_dir = '0';
	data->player_pos[0] = 0;
	data->player_pos[1] = 0;
	parse_map(map, data);
	parse_color(data);
	i = 0;
	//test - delete
	// printf("%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d %d\n%d %d %d\n%d %d %d\n",
	//  data->so, data->no, data->we, data->ea, data->fl, data->cl, data->player_dir,
	//  data->player_pos[0], data->player_pos[1], data->floor[0], data->floor[1], data->floor[2], 
	//  data->ceil[0], data->ceil[1], data->ceil[2]);
	// while (map[i]) 
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	return (map);
}