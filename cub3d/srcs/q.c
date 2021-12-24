#include "../cub3d.h"

// char player->data->map[mapWidth][mapHeight]=
// {
//   {"1111111111111111111111111111"},
//   {"1000000000000000000000000001"},
//   {"1000000000000000000000000001"},
//   {"1000000000000000000000000001"},
//   {"1000001111100011000101010001"},
//   {"1000001000100001000000000001"},
//   {"1000001000100001000100010001"},
//   {"1000001000100001000000000001"},
//   {"1000001101100011000101010001"},
//   {"1000000000000000000000000001"},
//   {"1000000000000000000000000001"},
//   {"1000000000000000000000000001"},
//   {"1000000000001100100010000001"},
//   {"1000000000000000100010000001"},
//   {"1000000000000000100010000001"},
//   {"1000000000000000100010000001"},
//   {"1111111110000000100010000001"},
//   {"1101000010000000000010000001"},
//   {"1100001010000000000000000001"},
//   {"1101000010000000000000000001"},
//   {"1101111110000000000000000001"},
//   {"1100000000000000000000000001"},
//   {"1111111110000000000000000001"},
//   {"1111111111111111111111111111"}
// };

static void	my_mlx_pixel_put2(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	verLine(t_win *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	int z = y1;
	int b = 0;
	while (b != z)
	{
		my_mlx_pixel_put2(info, x, b, 16777215);
		b++;
	}
	b = y2;
	while (b != screenHeight)
	{
		my_mlx_pixel_put2(info, x, b, 13120100);
		b++;
	}
	while (y <= y2)
	{
		my_mlx_pixel_put2(info, x, y, color);
		y++;
	}
}

void ft_step(t_tmp_value *tmp_value, double ray_dir_x, double ray_dir_y, t_player *player)
{
	int mapX = (int)player->x;
	int mapY = (int)player->y;
	double deltaDistX = fabs(1 / ray_dir_x);
	double deltaDistY = fabs(1 / ray_dir_y);
	if(ray_dir_x < 0)
	{
		tmp_value->step_x = -1;
		tmp_value->side_dist_x = (player->x - mapX) * deltaDistX;
	}
	else
	{
		tmp_value->step_x = 1;
		tmp_value->side_dist_x = (mapX + 1.0 - player->x) * deltaDistX;
	}
	if(ray_dir_y < 0)
	{
		tmp_value->step_y = -1;
		tmp_value->side_dist_y = (player->y - mapY) * deltaDistY;
	}
	else
	{
		tmp_value->step_y = 1;
		tmp_value->side_dist_y = (mapY + 1.0 - player->y) * deltaDistY;
	}
}

int check_hit(t_tmp_value *tmp_value, t_player *player, double ray_dir_x, double ray_dir_y)
{
	double deltaDistX = fabs(1 / ray_dir_x);
	double deltaDistY = fabs(1 / ray_dir_y);
	int hit = 0; //was there a wall hit?
	int side;

	while(hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if(tmp_value->side_dist_x < tmp_value->side_dist_y)
		{
			tmp_value->side_dist_x += deltaDistX;
			tmp_value->map_x += tmp_value->step_x;
			side = 0;
		}
		else
		{
			tmp_value->side_dist_y += deltaDistY;
			tmp_value->map_y += tmp_value->step_y;
			side = 1;
		}
		//Check if ray has hit a wall
		if (player->data->map[tmp_value->map_x][tmp_value->map_y] == '1')
			hit = 1;
	}
	return (side);
}

int foo(t_player *player)
{
	t_tmp_value *tmp_value = malloc(sizeof(t_tmp_value) * 1);
	ft_bzero(tmp_value, sizeof(t_tmp_value));
	int x = 0;
	while (x < screenWidth)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
		double rayDirX = player->dir_x + player->plane_x * cameraX;
		double rayDirY = player->dir_y + player->plane_y * cameraX;
		
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);

		double perpWallDist;

		
		int side; //was a NS or a EW wall hit?
	
		tmp_value->map_x = (int)player->x;
		tmp_value->map_y = (int)player->y;
		ft_step(tmp_value, rayDirX, rayDirY, player);

		side = check_hit(tmp_value, player, rayDirX, rayDirY);

		if(side == 0)
			perpWallDist = (tmp_value->side_dist_x - deltaDistX);
		else
			perpWallDist = (tmp_value->side_dist_y - deltaDistY);
		//Calculate height of line to draw on screen
		int lineHeight = (int)(screenHeight / perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		if (drawStart > screenHeight)
			drawStart = screenHeight - 1;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd > screenHeight)
			drawEnd = screenHeight - 1;
		if (drawEnd < 0)
			drawEnd = screenHeight - 1;
		int color = 48705;
		//give x and y sides different brightness
		if (side == 1)
			color = color / 2;
		int z = drawStart;
		verLine(player->data->win, x, drawStart, drawEnd, color);
		x++;
	}
	
	mlx_put_image_to_window(player->data->win->mlx, player->data->win->win, player->data->win->img, 0, 0);
	return 1;
}

void nazvanie_pridumayu_potom(t_data *data)
{
	data->player->dir_x = -1; // w
	data->player->dir_y = 0;
	// if (data->player_dir == 'E')
	// 	data->player->dir_x = 1;
	// else if (data->player_dir == 'N')
	// {
	// 	data->player->dir_x = 0;
	// 	data->player->dir_y = 1;
	// }
	// else if (data->player_dir == 'S')
	// {
	// 	data->player->dir_x = 0;
	// 	data->player->dir_y = -1;
	// }
	printf("%f %f\n", data->player->x, data->player->y);
	// data->player->x = 11 + 0.5;
	// data->player->y = 27 + 0.5;
	data->player->plane_x = 0;
	data->player->plane_y = 0.66;
	foo(data->player);
	// mlx_destroy_image(data->win->mlx, data->win->img);
	// mlx_hook(data->win->win, 2, 0, &key, data);

	// mlx_loop_hook(data->win->mlx, &foo, data);
	mlx_hook(data->win->win, 2, 0, &key, data->player);
	mlx_loop(data->win->mlx);
	// mlx_loop_hook(data->win->win, &foo, data);
}
