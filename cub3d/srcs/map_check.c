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
		return (1);
	return (0);
}

char	*list_to_string(char *content)
{
	char	*str;

	str = ft_strdup(content);
	if (!str)
	{
		ft_putstr_fd("Malloc error\n", STD_ERR);
		exit(0);
	}
	return (str);
}

void	fill_data(t_data *data, char *content)
{
	int	i;

	i = 0;
	while (content[i] == ' ')
			i++;
	if (content[i] == 'S' && content[i + 1] == 'O')
	{
		i += 2;
		while (content[i] == ' ')
			i++;
		data->so = ft_strdup((content + i));
	}
	else if (content[i] == 'N' && content[i + 1] == 'O')
	{
		i += 2;
		while (content[i] == ' ')
			i++;
		data->no = ft_strdup((content + i));
	}
	else if (content[i] == 'W' && content[i + 1] == 'E')
	{
		i += 2;
		while (content[i] == ' ')
			i++;
		data->we = ft_strdup((content + i));
	}
	else if (content[i] == 'E' && content[i + 1] == 'A')
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
		data->c = ft_strdup((content + i));
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

void	map_error()
{
	ft_putstr_fd("Map error\n", STD_ERR);
	exit(0);
}

void	parse_map(char **map)
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
			
		}
		i++;
	}
}

void	parse_color(char *floor, char *ceil, t_data *data)
{
	
}

char	**list_to_map(t_list **map_list, int size, t_data *data)
{
	char	**map;
	int	i;
	t_list	*tmp;
	int	k;

	map = (char **)malloc(sizeof(char *) * (size + 1 - 6));
	if (!map)
	{
		ft_putstr_fd("Malloc error\n", STD_ERR);
		exit(0);
	}
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
			i++;
		}
		tmp = tmp->next;
		k++;
	}
	map[i] = NULL;
	ft_lst_free(map_list); //free list, ne nuzhen bolshe - check leaks
	i = 0;
	//test - delete
	printf("%s\n%s\n%s\n%s\n%s\n%s\n", data->so, data->no, data->we, data->ea, data->fl, data->c);
	while (map[i]) 
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (map);
}