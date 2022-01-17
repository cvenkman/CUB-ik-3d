/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_verline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:27:24 by cvenkman          #+#    #+#             */
/*   Updated: 2022/01/17 19:27:51 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	my_mlx_pixel_put(t_win *win, int x, int y, int color);
static int	print_texture(t_player *player, int i, int x);

void	draw_verline(t_win *info, int x, int y_start, t_data *data)
{
	int	b;

	b = 0;
	while (b < y_start)
	{
		my_mlx_pixel_put(info, x, b, data->f);
		b++;
	}
	b = print_texture(data->player, b, x);
	while (b < SCREEN_H)
	{
		my_mlx_pixel_put(info, x, b, data->c);
		b++;
	}
}

static void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static int	print_texture(t_player *player, int i, int x)
{
	int	color;
	int	tex_y;

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
		i++;
	}
	return (i);
}
