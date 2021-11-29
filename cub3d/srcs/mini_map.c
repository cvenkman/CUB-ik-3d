#include "../cub3d.h"
# define AJA	8
// # define RA	4
static void	my_mlx_pixel_put(t_win *window, int x, int y, int color, int ajaraguju)
{
	int		i;
	int		j;

	i = 0;
	while (i < ajaraguju)
	{
		j = 0;
		while (j < ajaraguju)
		{
			mlx_pixel_put(window->mlx, window->win, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void ft_game(t_data *data)
{
	int x, y;

	x = data->player->x;
	y = data->player->y;
	printf("%d %d\n", data->player->y, data->player->x);
	if (data->player->W == true && data->map[data->player->y - 1][data->player->x] != '1')
		data->player->y--;
	else if (data->player->A == true && data->map[data->player->y][data->player->x - 1] != '1')
		data->player->x--;
	else if (data->player->S == true && data->map[data->player->y + 1][data->player->x] != '1')
		data->player->y++;
	if (data->player->D == true && data->map[data->player->y][data->player->x + 1] != '1')
		data->player->x++;
	if (data->player->x != x || data->player->y != y)
		my_mlx_pixel_put(data->win, x * AJA, y * AJA, BLACK, AJA);
	my_mlx_pixel_put(data->win, data->player->x * AJA, data->player->y * AJA, PINK, AJA);
}

int	ft_key(int keycode, t_data *data)
{
	data->player->W = false;
	data->player->A = false;
	data->player->S = false;
	data->player->D = false;
	if (keycode == KEY_W)
		data->player->W = true;
	if (keycode == KEY_A)
		data->player->A = true;
	if (keycode == KEY_S)
		data->player->S = true;
	if (keycode == KEY_D)
		data->player->D = true;
	ft_game(data);
	return (1);
}

void mini_map_draw(t_data *data)
{
	int	x;
	int	y;
	int		i;

	i = 0;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == '1')
				my_mlx_pixel_put(data->win, x * AJA, y * AJA, 7895, AJA);
			if (data->map[y][x] == 'N')
			{
				my_mlx_pixel_put(data->win, x * AJA, y * AJA, PINK, AJA);
				data->player->x = x;
				data->player->y = y;
			}
			x++;
		}
		y++;
	}
	printf("!! %d %d\n", data->player->x, data->player->y);
	mlx_hook(data->win->win, 2, 0, ft_key, data);
	// mlx_put_image_to_window(data->window->mlx, data->window->win, data->window->img, 0, 0);
}
