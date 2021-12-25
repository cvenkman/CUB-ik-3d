#include "../cub3d.h"

static void init_NS(t_data *data);

void init_WE(t_data *data)
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
		init_NS(data);
}

static void init_NS(t_data *data)
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
