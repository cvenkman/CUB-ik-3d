#include "../cub3d.h"

static void draw_floor_and_сeiling(int y_start, int y_end, t_win *info, int x, t_data *data);
static void	my_mlx_pixel_put(t_win *win, int x, int y, int color);
int	print_texture(t_player *player, int i, int x);

void	draw_verLine(t_win *info, int x, int y_start, int y_end, t_data *data, int color)
{
	draw_floor_and_сeiling(y_start, y_end, info, x, data);
	// while (y_start <= y_end)
	// {
	// 	my_mlx_pixel_put(info, x, y_start, color);
	// 	y_start++;
	// }
}

static void draw_floor_and_сeiling(int y_start, int y_end, t_win *info, int x, t_data *data)
{
	int b = 0;
	while (b < y_start)
	{
		my_mlx_pixel_put(info, x, b, 16777215);
		b++;
	}
	b = print_texture(data->player, b, x);
	// b = y_end;
	while (b < SCREEN_H)
	{
		my_mlx_pixel_put(info, x, b, 13120100);
		b++;
	}
}

static void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	// if (x < 0 || x > SCREEN_W || y < 0 || y > SCREEN_H)
	// 	return ;
	
	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	// mlx_pixel_put(win->mlx, win->win, x, y, color);
}

int	print_texture(t_player *player, int i, int x)
{
	int	color;
	int	tex_y;

	// printf("%d\n", player->draw_end);
	while (i <= player->draw_end)
	{
		tex_y = (int)player->tex_pos & (TEX_HEIGHT - 1);
		player->tex_pos += player->step;
		if (player->side == 1)
		{
			if (player->step_y == -1)
				color = player->data->texture->west[player->tex_x][tex_y];
			else
				color = player->data->texture->east[player->tex_x][tex_y];
		}
		else
		{
			if (player->step_x == -1)
				color = player->data->texture->north[player->tex_x][tex_y];
			else
				color = player->data->texture->south[player->tex_x][tex_y];
		}
		my_mlx_pixel_put(player->data->win, x, i, color);
		// mlx_pixel_put(player->data->win->mlx, player->data->win->win, x, i, color);
		i++;
	}
	return (i);
}

