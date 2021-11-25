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
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			k++;
		i++;
	}
	if (k == i)
		return (1);
	return (0);
}

char	*list_to_string(char *content)
{
	char	*str;
	int	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(content) + 1));
	if (!str)
	{
		ft_putstr_fd("Malloc error\n", STD_ERR);
		exit(0);
	}
	ft_strcpy(str, content);
	return (str);
}

char	**list_to_map(t_list **map_list, int size)
{
	char	**map;
	int	i;
	t_list	*tmp;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
	{
		ft_putstr_fd("Malloc error\n", STD_ERR);
		exit(0);
	}
	tmp = *map_list;
	i = 0;
	while (tmp)
	{
		map[i] = list_to_string(tmp->content);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	//free list
	i = 0;
	// while (map[i]) //test - delete
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	return (map);
}