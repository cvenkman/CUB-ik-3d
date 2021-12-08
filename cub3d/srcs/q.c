#include "../cub3d.h"
#include <math.h>

#define w screenWidth
#define h screenHeight

#define SPEED 0.15
#define ROT_SPEED 0.05 // SPEED / 3.0


static void	my_mlx_pixel_put2(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int foo(t_player *player)
{
	//move forward if no wall in front of you
	if (player->W == true)
	{
		if (player->data->map[(int)(player->x + player->dir_x * SPEED)][(int)(player->y)] == '0')
			player->x += player->dir_x * SPEED;
		if (player->data->map[(int)(player->x)][(int)(player->y + player->dir_y * SPEED)] == '0')
			player->y += player->dir_y * SPEED;
	}
	//move backwards if no wall behind you
	if (player->S == true)
	{
		if (player->data->map[(int)(player->x - player->dir_x * SPEED)][(int)(player->y)] == '0')
			player->x -= player->dir_x * SPEED;
		if (player->data->map[(int)(player->x)][(int)(player->y - player->dir_x * SPEED)] == '0')
			player->y -= player->dir_y * SPEED;
	}

    // double rotSpeed = SPEED / 3.0; //the constant value is in radians/second

    if(player->D == true) 
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
    if (player->A == true)
    {
		//both camera direction and camera plane must be rotated
		double oldDirX = player->dir_x;
		player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y * sin(ROT_SPEED);
		player->dir_y = oldDirX * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
		double oldPlaneX = player->plane_x;
		player->plane_x = player->plane_x * cos(ROT_SPEED) - player->plane_y * sin(ROT_SPEED);
		player->plane_y = oldPlaneX * sin(ROT_SPEED) + player->plane_y * cos(ROT_SPEED);
    }

	int x = 0;
	while (x < screenWidth)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
		double rayDirX = player->dir_x + player->plane_x * cameraX;
		double rayDirY = player->dir_y + player->plane_y * cameraX;
		//which box of the map we're in
		int mapX = (int)player->x;
		int mapY = (int)player->y;
		printf("%f %f\n", player->x, player->y);

		double sideDistX;
		double sideDistY;
		
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
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
			if (mapX >= player->data->map_h) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				mapX = player->data->map_h - 1;
			// if (mapY )
			if (player->data->map[mapX][mapY] == '1')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(screenHeight / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd > screenHeight)
			drawEnd = screenHeight - 1;
		int color = 48705;
		//give x and y sides different brightness
		if (side == 1)
			color = color / 2;
		int z = drawStart;
		//draw the pixels of the stripe as a vertical line
		while (drawStart <= drawEnd)
		{
			my_mlx_pixel_put2(player->data->win, x, drawStart, color);
			drawStart++;
		}
		int b = 0;
		while (b != z)
		{
			my_mlx_pixel_put2(player->data->win, x, b, 16777215);
			b++;
		}
		b = drawEnd;
		while (b != screenHeight)
		{
			my_mlx_pixel_put2(player->data->win, x, b, 16776960);
			b++;
		}
		x++;
	}
	mlx_put_image_to_window(player->data->win->mlx, player->data->win->win, player->data->win->img, 0, 0);
	return 1;
}


int	key(int keycode, t_data *data)
{
	data->player->W = false;
	data->player->A = false;
	data->player->S = false;
	data->player->D = false;
	if (keycode == KEY_W)
		data->player->W = true;
	if (keycode == KEY_A)
		data->player->A = true;
	if (keycode == KEY_S)
		data->player->S = true;
	if (keycode == KEY_D)
		data->player->D = true;
	foo(data->player);
	return 1;
}

void nazvanie_pridumayu_potom(t_data *data)
{
	data->player->dir_x = -1;
	data->player->dir_y = 0;
	data->player->x = 22;
	data->player->y = 12;
	data->player->plane_x = 0;
	data->player->plane_y = 0.66;
	foo(data->player);
	mlx_hook(data->win->win, 2, 0, &key, data);
	// mlx_loop_hook(data->win->win, &foo, data);
}
