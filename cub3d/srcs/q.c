#include "../cub3d.h"
#include <math.h>

#define w screenWidth
#define h screenHeight

#define SPEED 0.15
#define ROT_SPEED 0.05 // SPEED / 3.0

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
	while (y <= y2)
	{
		my_mlx_pixel_put2(info, x, y, color);
		y++;
	}
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
	// my_mlx_pixel_put2(info, x, b, 13120100);
}

int foo(t_player *player)
{
	int x = 0;
	while (x < screenWidth)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
		double rayDirX = player->dir_x + player->plane_x * cameraX;
		double rayDirY = player->dir_y + player->plane_y * cameraX;
		//which box of the map we're in
		// printf("%f %f\n", player->x, player->y);

		double sideDistX;
		double sideDistY;
		
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		int mapX = (int)player->x;
		int mapY = (int)player->y;
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player->x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player->y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player->y) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (player->data->map[mapX][mapY] == '1' || player->data->map[mapX][mapY] == 'N')
				hit = 1;
		}
		// if (side == 0)
		// 	perpWallDist = (mapX - player->x + (1 - stepX) / 2) / rayDirX;
		// else
		// 	perpWallDist = (mapY - player->y + (1 - stepY) / 2) / rayDirY;
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
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
		//draw the pixels of the stripe as a vertical line
		// printf("%d %d %d\n", drawStart, drawEnd, lineHeight);
		verLine(player->data->win, x, drawStart, drawEnd, color);
		// while (drawStart <= drawEnd)
		// {
		// 	my_mlx_pixel_put2(player->data->win, x, drawStart, color);
		// 	drawStart++;
		// }
		// int b = 0;
		// while (b != z)
		// {
		// 	my_mlx_pixel_put2(player->data->win, x, b, 16777215);
		// 	b++;
		// }
		// b = drawEnd;
		// while (b != screenHeight)
		// {
		// 	my_mlx_pixel_put2(player->data->win, x, b, 16776960);
		// 	b++;
		// }
		x++;
	}
	
	mlx_put_image_to_window(player->data->win->mlx, player->data->win->win, player->data->win->img, 0, 0);
	// mlx_destroy_image(player->data->win->mlx, player->data->win->img);
	return 1;
}


int	key(int keycode, t_player *player)
{
	// t_player *palyer = data->pla 
	// data->player->W = false;
	// data->player->A = false;
	// data->player->S = false;
	// data->player->D = false;
	// if (keycode == KEY_W)
	// 	data->player->W = true;
	// if (keycode == KEY_A)
	// 	data->player->A = true;
	// if (keycode == KEY_S)
	// 	data->player->S = true;
	// if (keycode == KEY_D)
	// 	data->player->D = true;
	// foo(data->player);
	//move forward if no wall in front of you
	if (keycode == KEY_W)
	{
		if (player->data->map[(int)(player->x + player->dir_x * SPEED)][(int)(player->y)] == '0')
			player->x += player->dir_x * SPEED;
		if (player->data->map[(int)(player->x)][(int)(player->y + player->dir_y * SPEED)] == '0')
			player->y += player->dir_y * SPEED;
	}
	if (keycode == KEY_A)
	{
		if (player->data->map[(int)(player->x - player->plane_x * SPEED)][(int)(player->y)] == '0')
			player->x -= player->plane_x * SPEED;
		if (player->data->map[(int)(player->x)][(int)(player->y - player->plane_y * SPEED)] == '0')
			player->y -= player->plane_y * SPEED;
	}
	//move backwards if no wall behind you
	if (keycode == KEY_S)
	{
		if (player->data->map[(int)(player->x - player->dir_x * SPEED)][(int)(player->y)] == '0')
			player->x -= player->dir_x * SPEED;
		if (player->data->map[(int)(player->x)][(int)(player->y - player->dir_x * SPEED)] == '0')
			player->y -= player->dir_y * SPEED;
	}
	if (keycode == KEY_D)
	{
		if (player->data->map[(int)(player->x + player->plane_x * SPEED)][(int)(player->y)] == '0')
			player->x += player->plane_x * SPEED;
		if (player->data->map[(int)(player->x)][(int)(player->y + player->plane_y * SPEED)] == '0')
			player->y += player->plane_y * SPEED;
	}
    // double rotSpeed = SPEED / 3.0; //the constant value is in radians/second

    if(keycode == KEY_ARR_R) 
    {
		//both camera direction and camera plane must be rotated
		double oldDirX = player->dir_x;
		player->dir_x = player->dir_x * cos(-ROT_SPEED) - player->dir_y * sin(-ROT_SPEED);
		player->dir_y = oldDirX * sin(-ROT_SPEED) + player->dir_y * cos(-ROT_SPEED);
		double oldPlaneX = player->plane_x;
		player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y * sin(-ROT_SPEED);
		player->plane_y = oldPlaneX * sin(-ROT_SPEED) + player->plane_y * cos(-ROT_SPEED);
    }
    //rotate to the left
    if (keycode == KEY_ARR_L)
    {
		//both camera direction and camera plane must be rotated
		double oldDirX = player->dir_x;
		player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y * sin(ROT_SPEED);
		player->dir_y = oldDirX * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
		double oldPlaneX = player->plane_x;
		player->plane_x = player->plane_x * cos(ROT_SPEED) - player->plane_y * sin(ROT_SPEED);
		player->plane_y = oldPlaneX * sin(ROT_SPEED) + player->plane_y * cos(ROT_SPEED);
    }
	if (keycode == 53)
		exit(0);
	printf("%d\n", keycode);
	foo(player);
	return 1;
}

void nazvanie_pridumayu_potom(t_data *data)
{
	data->player->dir_x = -1;
	data->player->dir_y = 0;
	// printf("%f %f\n", data->player->x, data->player->y);
	data->player->x = 19;
	data->player->y = 18;
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
