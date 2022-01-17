/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodevs_calculations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:07:42 by cvenkman          #+#    #+#             */
/*   Updated: 2022/01/17 19:27:59 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	step_and_side_dist(t_player *player)
{
	if (player->ray_dir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->x - player->map_x)
			* player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1.0 - player->x)
			* player->delta_dist_x;
	}
	if (player->ray_dir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->y - player->map_y)
			* player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1.0 - player->y)
			* player->delta_dist_y;
	}
}

void	dda(t_player *player)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (player->data->map[player->map_x][player->map_y] == '1')
			hit = 1;
	}
}

void	ft_perp_wall_dist(t_player *player)
{
	if (player->side == 0)
		player->perp_wall_dist = (player->side_dist_x
				- player->delta_dist_x);
	else
		player->perp_wall_dist = (player->side_dist_y
				- player->delta_dist_y);
}

void	line_start_and_end(t_player *player)
{
	player->line_height = (int)(SCREEN_H / player->perp_wall_dist);
	player->draw_start = -player->line_height / 2 + SCREEN_H / 2;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = player->line_height / 2 + SCREEN_H / 2;
	if (player->draw_end > SCREEN_H)
		player->draw_end = SCREEN_H - 1;
}

void	for_textures(t_player *player)
{
	if (player->side == 0)
		player->wall_x = player->y + player->perp_wall_dist * player->ray_dir_y;
	else
		player->wall_x = player->x + player->perp_wall_dist * player->ray_dir_x;
	player->wall_x -= floor(player->wall_x);
	player->tex_x = (int)(player->wall_x * (double)TEX_WIDTH);
	player->tex_x = TEX_WIDTH - player->tex_x - 1;
	player->step = 1.0 * TEX_HEIGHT / player->line_height;
	player->tex_pos = (player->draw_start - SCREEN_H
			/ 2 + player->line_height / 2) * player->step;
}
