/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:01:44 by cvenkman          #+#    #+#             */
/*   Updated: 2021/12/26 20:48:43 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_mlx(t_win *window);
void		parse(t_data *data, int argc, char **argv);
static void	delete_n_in_map_and_find_player(t_data *data, char **map);
void		init_mlx_and_textures(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	parse(&data, argc, argv);
	init_we(&data);
	init_mlx_and_textures(&data);
	data.player->data = &data;
	data.f = (data.floor[2] << 16) + (data.floor[1] << 8) + data.floor[0];
	data.c = (data.ceil[2] << 16) + (data.ceil[1] << 8) + data.ceil[0];
	start_raycasting(&data);
	return (0);
}

void	parse(t_data *data, int argc, char **argv)
{
	int		fd;
	char	*cur_str;
	t_list	*map_list;
	char	**map;

	cur_str = NULL;
	map_list = NULL;
	fd = map_check(argc, argv);
	while (get_next_line(fd, &cur_str))
		if (ft_lstsize(map_list) > 6 || !str_is_empty(cur_str))
			ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	ft_lstadd_back(&map_list, ft_lstnew(cur_str));
	close(fd);
	data->win = malloc(sizeof(t_win) * 1);
	data->player = malloc(sizeof(t_player) * 1);
	data->texture = malloc(sizeof(t_texture) * 1);
	ft_bzero(data->texture, sizeof(t_texture));
	init_data(data);
	map = list_to_map(&map_list, ft_lstsize(map_list), data, -1);
	delete_n_in_map_and_find_player(data, map);
}

static void	delete_n_in_map_and_find_player(t_data *data, char **map)
{
	int	j;
	int	i;

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
				data->map[i][j] = '0';
			}
			else
				data->map[i][j] = map[i][j];
			j++;
		}
		data->map[i][j] = '\0';
	}
	data->player->y = data->player_pos[1] + 0.5;
	data->player->x = data->player_pos[0] + 0.5;
	data->map[i] = NULL;
}

void	init_mlx_and_textures(t_data *data)
{
	init_mlx(data->win);
	data->win->size_img.x = SCREEN_W;
	data->win->size_img.y = SCREEN_H;
	init_texture(data);
}

static void	init_mlx(t_win *window)
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
