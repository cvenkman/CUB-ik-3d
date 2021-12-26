/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:50:27 by cvenkman          #+#    #+#             */
/*   Updated: 2021/12/26 20:50:56 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	start_raycasting(t_data *data)
{
	mlx_loop_hook(data->win->mlx, (void *)raycasting, data->player);
	mlx_hook(data->win->win, 2, 0, &key, data->player);
	mlx_loop(data->win->mlx);
}

void	raycasting(t_player *player)
{
	int		x;
	double	camera_x;

	x = 0;
	while (x < SCREEN_W)
	{
		camera_x = 2 * x / (double)SCREEN_W - 1;
		player->map_x = (int)player->x;
		player->map_y = (int)player->y;
		player->ray_dir_x = player->dir_x + player->plane_x * camera_x;
		player->ray_dir_y = player->dir_y + player->plane_y * camera_x;
		player->delta_dist_x = fabs(1 / player->ray_dir_x);
		player->delta_dist_y = fabs(1 / player->ray_dir_y);
		step_and_side_dist(player);
		dda(player);
		ft_perp_wall_dist(player);
		line_start_and_end(player);
		for_textures(player);
		draw_verline(player->data->win, x, player->draw_start,
			player->data);
		x++;
	}
	mlx_put_image_to_window(player->data->win->mlx,
		player->data->win->win, player->data->win->img, 0, 0);
}
