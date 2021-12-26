/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:17:22 by cvenkman          #+#    #+#             */
/*   Updated: 2021/12/26 20:17:39 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	init_ns(t_data *data);

void	init_we(t_data *data)
{
	if (data->player_dir == 'W')
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
		data->player->plane_x = -0.66;
		data->player->plane_y = 0;
	}
	else if (data->player_dir == 'E')
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
		data->player->plane_x = 0.66;
		data->player->plane_y = 0;
	}
	else
		init_ns(data);
}

static void	init_ns(t_data *data)
{
	if (data->player_dir == 'N')
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = 0.66;
	}
	else if (data->player_dir == 'S')
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = -0.66;
	}
}
