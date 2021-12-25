#include "../cub3d.h"
// # define AJA	16
// // # define RA	4
// #include <math.h>
// static void	my_mlx_pixel_put2(t_win *win, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
// void	my_mlx_pixel_put(t_win *window, int x, int y, int color, int ajaraguju)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < ajaraguju)
// 	{
// 		j = 0;
// 		while (j < ajaraguju)
// 		{
// 			my_mlx_pixel_put2(window, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// // void boo(t_data *data)
// // {
// // 	t_player plr = *data->player;

// 	// plr.start = plr.dir - M_PI_4;
// 	// plr.end = plr.dir + M_PI_4;
// 	// while (plr.start < plr.end)
// 	// {
// 	// 	plr.x = data->player->x;
// 	// 	plr.y = data->player->y;
// 		// while (data->map[(int)(plr.y / AJA)] != NULL &&
// 		// 	data->map[(int)(plr.y / AJA)][(int)(plr.x / AJA)] != '1')
// 		// {
// 		// 	plr.x += cos(plr.dir);
// 		// 	plr.y += sin(plr.dir);
// 		// 	my_mlx_pixel_put2(data->win, plr.x, plr.y, 48705);
// 		// 	// printf("%f %f\n", plr.x, plr.y);
// 		// }
// 		// plr.start += M_PI_4 / 40;
// 	// }
// // }

// void ft_game(t_data *data)
// {
// 	int x, y;

// 	x = data->player->x;
// 	y = data->player->y;
// 	// printf("%f %f\n", data->player->y, data->player->x);
// 	// if (data->player->W == true &&
// 	// 	data->map[(int)((data->player->y + sin(data->player->dir) * 4) / AJA)][(int)((data->player->x + cos(data->player->dir) * 4) / AJA)] != '1')
// 	// {
// 	// 	data->player->y += sin(data->player->dir) * 4;
// 	// 	data->player->x += cos(data->player->dir) * 4;
// 	// }
// 	// else if (data->player->A == true)
// 	// {
// 	// 	data->player->dir -= 0.1;
// 	// }
// 	// else if (data->player->S == true)
// 	// {
// 	// 	data->player->y -= sin(data->player->dir) * 4;
// 	// 	data->player->x -= cos(data->player->dir) * 4;
// 	// }
// 	// if (data->player->D == true)
// 	// {
// 	// 	data->player->dir += 0.1;
// 	// }
// 		// printf("%c\n", data->map[(int)(data->player->y / AJA)][(int)(data->player->x / AJA)]);
// 	// if (data->map[(int)(data->player->y / AJA)][(int)(data->player->x / AJA)] == '1')
// 	// {
// 	// 	data->player->x = x;
// 	// 	data->player->y = y;
// 	// 	return ;
// 	// }

// 	/**
// 	*	!!!!! / AJA
// 	**/
// 	// if (data->player->W == true && data->map[(int)(data->player->y - 1)][(int)data->player->x] != '1')
// 	// 	data->player->y--;
// 	// else if (data->player->A == true && data->map[(int)data->player->y][(int)(data->player->x - 1)] != '1')
// 	// 	data->player->x--;
// 	// else if (data->player->S == true && data->map[(int)(data->player->y + 1)][(int)data->player->x] != '1')
// 	// 	data->player->y++;
// 	// if (data->player->D == true && data->map[(int)data->player->y][(int)(data->player->x + 1)] != '1')
// 	// 	data->player->x++;
// 	// if (data->player->x != x || data->player->y != y)
// 		// my_mlx_pixel_put(data->win, x, y, BLACK, AJA);
// 	my_mlx_pixel_put(data->win, data->player->x, data->player->y, PINK, AJA);
// 	// boo(data);
// 	mlx_put_image_to_window(data->win->mlx, data->win->win, data->win->img, 0, 0);
// }

// int	ft_key(int keycode, t_data *data)
// {
// 	data->player->W = false;
// 	data->player->A = false;
// 	data->player->S = false;
// 	data->player->D = false;
// 	if (keycode == KEY_W)
// 		data->player->W = true;
// 	if (keycode == KEY_A)
// 		data->player->A = true;
// 	if (keycode == KEY_S)
// 		data->player->S = true;
// 	if (keycode == KEY_D)
// 		data->player->D = true;
// 	if (keycode == ESC)
// 		exit (0);
// 	ft_game(data);
// 	return (1);
// }

// void mini_map_draw(t_data *data)
// {
// 	int	x;
// 	int	y;
// 	int		i;

// 	i = 0;

// 	y = 0;
// 	printf("больше ничего не хочешь? не работает тут ничего\n");
// 	exit(0);
// 	// data->player->dir = 3 * M_PI_2;
// 	// while (data->map[y] != NULL)
// 	// {
// 	// 	x = 0;
// 		//7864420 - фиолетовый
// 		//9856100
// 		//48705 зеленый
// 		//16777215 - white
// 		// dark blue 255
// 		// blue 23200
// 		// red 16711680
// 		//yellow 16776960
// 		// grey 6579300
// 		// pink 13120100
// 	// 	while (data->map[y][x] != '\0')
// 	// 	{
// 	// 		if (data->map[y][x] == '1')
// 	// 			my_mlx_pixel_put(data->win, x * AJA, y * AJA, 7864420, AJA);
// 	// 		if (data->map[y][x] == 'N')
// 	// 		{
// 	// 			data->player->x = x * AJA;
// 	// 			data->player->y = y * AJA;
// 	// 			my_mlx_pixel_put(data->win, x * AJA, y * AJA, PINK, AJA);
// 	// 		}
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// 	// mlx_put_image_to_window(data->win->mlx, data->win->win, data->win->img, 0, 0);
// 	// mlx_hook(data->win->win, 2, 0, ft_key, data);
// }
