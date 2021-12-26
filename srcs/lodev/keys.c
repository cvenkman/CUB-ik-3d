/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:18:19 by cvenkman          #+#    #+#             */
/*   Updated: 2021/12/26 20:23:16 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	key_l_arr(t_player *player);
static void	key_r_arr(t_player *player);

int	key(int keycode, t_player *player)
{
	if (keycode == KEY_W)
		key_w(player);
	if (keycode == KEY_A)
		key_a(player);
	if (keycode == KEY_S)
		key_s(player);
	if (keycode == KEY_D)
		key_d(player);
	if (keycode == KEY_ARR_R)
		key_r_arr(player);
	if (keycode == KEY_ARR_L)
		key_l_arr(player);
	if (keycode == 53)
		exit(0);
	raycasting(player);
	return (1);
}

static void	key_l_arr(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y
		* sin(ROT_SPEED);
	player->dir_y = old_dir_x * sin(ROT_SPEED) + player->dir_y
		* cos(ROT_SPEED);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(ROT_SPEED) - player->plane_y
		* sin(ROT_SPEED);
	player->plane_y = old_plane_x * sin(ROT_SPEED) + player->plane_y
		* cos(ROT_SPEED);
}

static void	key_r_arr(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-ROT_SPEED) - player->dir_y
		* sin(-ROT_SPEED);
	player->dir_y = old_dir_x * sin(-ROT_SPEED) + player->dir_y
		* cos(-ROT_SPEED);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y
		* sin(-ROT_SPEED);
	player->plane_y = old_plane_x * sin(-ROT_SPEED) + player->plane_y
		* cos(-ROT_SPEED);
}
