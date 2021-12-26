/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:49:30 by rloyce            #+#    #+#             */
/*   Updated: 2021/12/26 22:26:50 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	map_check(int argc, char **argv)
{
	int	size;
	int	fd;

	if (argc != 2)
		first_errors(1);
	size = ft_strlen(argv[1]);
	if (size < 4 || (ft_strncmp(argv[1] + size - 4, ".cub", 4) != 0))
		first_errors(2);
	fd = open(argv[1], O_DIRECTORY);
	if (fd > 0)
		first_errors(3);
	close (fd);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		first_errors(4);
	return (fd);
}

void	check_map_in(char **map, int y, int x)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (y == 0 || x == 0 || x == (int)(ft_strlen(map[y]) - 1) || y == i - 1)
		map_error();
	else if (x >= (int)(ft_strlen(map[y - 1])) ||
		x >= (int)(ft_strlen(map[y + 1])))
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

	i = -1;
	while (map[++i])
	{
		j = -1;
		if (map[i][0] == '\0')
			map_error();
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W')
				map_error();
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				check_map_in(map, i, j);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				check_map_player(map, i, j, data);
		}
	}
	if (data->player_pos[0] == 0 || data->player_pos[1] == 0)
		map_error();
}

char	**list_to_map(t_list **map_list, int size, t_data *data, int k)
{
	char	**map;
	t_list	*tmp;
	int		i;

	map = (char **)malloc(sizeof(char *) * (size + 1 - 6));
	if (!map)
		malloc_error();
	tmp = *map_list;
	i = 0;
	while (tmp)
	{
		if (++k <= 5)
			fill_data(data, tmp->content);
		if (k > 5)
		{
			map[i++] = list_to_string(tmp->content);
			data->map_h++;
		}
		tmp = tmp->next;
	}
	map[i] = NULL;
	ft_lst_free(map_list);
	parse_map(map, data);
	parse_color(data);
	return (map);
}
