/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gitt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:12:25 by yohan             #+#    #+#             */
/*   Updated: 2021/12/13 21:51:32 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../mlx/mlx.h"
// #include "key_macos.h"
// #include <math.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// #define X_EVENT_KEY_PRESS	2
// #define X_EVENT_KEY_EXIT	17
// #define mapWidth 24
// #define mapHeight 24
// #define width 640
// #define height 480

// typedef struct	s_info
// {
// 	double posX;
// 	double posY;
// 	double dirX;
// 	double dirY;
// 	double planeX;
// 	double planeY;
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	double	moveSpeed;
// 	double	rotSpeed;
	
// }				t_info;

// int	worldMap[24][24] = {
// 							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// 							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
// 							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// 						};

// static void	my_mlx_pixel_put_22(t_info *win, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	verLine(t_info *info, int x, int y1, int y2, int color)
// {
// 	int	y;

// 	y = y1;
// 	int z = y1;
// 	while (y <= y2)
// 	{
// 		my_mlx_pixel_put_22(info, x, y, color);
// 		y++;
// 	}
// 	int b = 0;
// 	while (b != z)
// 	{
// 		my_mlx_pixel_put_22(info, x, b, 16777215);
// 		b++;
// 	}
// 	b = y2;
// 	while (b != height)
// 	{
// 		my_mlx_pixel_put_22(info, x, b, 13120100);
// 		b++;
// 	}
// }

// void	calc(t_info *info)
// {
// 	int	x;

// 	x = 0;
// 	while (x < width)
// 	{
// 		double cameraX = 2 * x / (double)width - 1;
// 		double rayDirX = info->dirX + info->planeX * cameraX;
// 		double rayDirY = info->dirY + info->planeY * cameraX;
		
// 		int mapX = (int)info->posX;
// 		int mapY = (int)info->posY;

// 		//length of ray from current position to next x or y-side
// 		double sideDistX;
// 		double sideDistY;
		
// 		 //length of ray from one x or y-side to next x or y-side
// 		double deltaDistX = fabs(1 / rayDirX);
// 		double deltaDistY = fabs(1 / rayDirY);
// 		double perpWallDist;
		
// 		//what direction to step in x or y-direction (either +1 or -1)
// 		int stepX;
// 		int stepY;
		
// 		int hit = 0; //was there a wall hit?
// 		int side; //was a NS or a EW wall hit?

// 		if (rayDirX < 0)
// 		{
// 			stepX = -1;
// 			sideDistX = (info->posX - mapX) * deltaDistX;
// 		}
// 		else
// 		{
// 			stepX = 1;
// 			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
// 		}
// 		if (rayDirY < 0)
// 		{
// 			stepY = -1;
// 			sideDistY = (info->posY - mapY) * deltaDistY;
// 		}
// 		else
// 		{
// 			stepY = 1;
// 			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
// 		}

// 		while (hit == 0)
// 		{
// 			//jump to next map square, OR in x-direction, OR in y-direction
// 			if (sideDistX < sideDistY)
// 			{
// 				sideDistX += deltaDistX;
// 				mapX += stepX;
// 				side = 0;
// 			}
// 			else
// 			{
// 				sideDistY += deltaDistY;
// 				mapY += stepY;
// 				side = 1;
// 			}
// 			//Check if ray has hit a wall
// 			if (worldMap[mapX][mapY] > 0) hit = 1;
// 		}
// 		if (side == 0)
// 			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
// 		else
// 			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

// 		//Calculate height of line to draw on screen
// 		int lineHeight = (int)(height / perpWallDist);

// 		//calculate lowest and highest pixel to fill in current stripe
// 		int drawStart = -lineHeight / 2 + height / 2;
// 		if(drawStart < 0)
// 			drawStart = 0;
// 		int drawEnd = lineHeight / 2 + height / 2;
// 		if(drawEnd >= height)
// 			drawEnd = height - 1;

// 		int	color;
// 		if (worldMap[mapY][mapX] > 0)
// 			color = 48705;
		
// 		if (side == 1)
// 			color = color / 2;

// 		verLine(info, x, drawStart, drawEnd, color);
		
// 		x++;
// 	}
// 	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);

// }

// int	main_loop(t_info *info)
// {
// 	calc(info);
// 	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);

// 	return (0);
// }

// int	key_press(int key, t_info *info)
// {
// 	if (key == K_W)
// 	{
// 		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
// 			info->posX += info->dirX * info->moveSpeed;
// 		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
// 			info->posY += info->dirY * info->moveSpeed;
// 	}
// 	//move backwards if no wall behind you
// 	if (key == K_S)
// 	{
// 		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
// 			info->posX -= info->dirX * info->moveSpeed;
// 		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
// 			info->posY -= info->dirY * info->moveSpeed;
// 	}
// 	//rotate to the right
// 	if (key == K_D)
// 	{
// 		//both camera direction and camera plane must be rotated
// 		double oldDirX = info->dirX;
// 		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
// 		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
// 		double oldPlaneX = info->planeX;
// 		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
// 		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
// 	}
// 	//rotate to the left
// 	if (key == K_A)
// 	{
// 		//both camera direction and camera plane must be rotated
// 		double oldDirX = info->dirX;
// 		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
// 		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
// 		double oldPlaneX = info->planeX;
// 		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
// 		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
// 	}
// 	if (key == K_ESC)
// 		exit(0);
// 	return (0);
// }

// int	main(void)
// {
// 	t_info info;
// 	info.mlx = mlx_init();

// 	info.posX = 12;
// 	info.posY = 5;
// 	info.dirX = -1;
// 	info.dirY = 0;
// 	info.planeX = 0;
// 	info.planeY = 0.66;
// 	info.moveSpeed = 0.05;
// 	info.rotSpeed = 0.05;
	
// 	info.win = mlx_new_window(info.mlx, width, height, "mlx");
// 	info.img = mlx_new_image(info.mlx, width, height);
// 	info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel, &info.line_length,
// 								&info.endian);
// 	mlx_loop_hook(info.mlx, &main_loop, &info);
// 	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

// 	mlx_loop(info.mlx);
// }