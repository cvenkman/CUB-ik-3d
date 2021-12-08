// #include "../cub3d.h"
// #include <math.h>
// #define w screenWidth
// #define h screenHeight
// char worldMap[mapWidth][mapHeight]=
// {
//   {"111111111111111111111111"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000111110000101010001"},
//   {"100000100010000000000001"},
//   {"100000100010000100010001"},
//   {"100000100010000000000001"},
//   {"100000110110000101010001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"100000000000000000000001"},
//   {"111111111000000000000001"},
//   {"110100001000000000000001"},
//   {"110000101000000000000001"},
//   {"110100001000000000000001"},
//   {"110111111000000000000001"},
//   {"110000000000000000000001"},
//   {"111111111000000000000001"},
//   {"111111111111111111111111"}
// };

// static void	my_mlx_pixel_put2(t_win *win, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// // void foo(double data->player->posX, double data->player->posY, double data->player->dirX, double data->player->dirY, double planeX, double planeY, t_data *data)
// int foo(t_data *data)
// {
//     // screen(screenWidth, screenHeight, 0, "Raycaster");
// 	// double data->player->posX = data->player->x, data->player->posY = data->player->y;  //x and y start position

// 	// double data->player->dirX = -1, data->player->dirY = 0; //initial direction vector
// 	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

// 		int x = 0;
// 		while (x < screenWidth)
// 		{
// 			// double moveSpeed = 0.12;
// 			// if(data->player->W == true)
// 			// {
// 			// 	// if(worldMap[(int)(data->player->posY)][(int)(data->player->posX - data->player->dirX * moveSpeed)] == false) data->player->posX -= data->player->dirX * moveSpeed;
// 			// 	// if(worldMap[(int)(data->player->posY - data->player->dirY * moveSpeed)][(int)(data->player->posX)] == false) data->player->posY -= data->player->dirY * moveSpeed;

// 			// 	if(worldMap[(int)(data->player->posX + data->player->dirX * moveSpeed)][(int)(data->player->posY)] == false) data->player->posX += data->player->dirX * moveSpeed;
// 			// 	if(worldMap[(int)(data->player->posX)][(int)(data->player->posY + data->player->dirY * moveSpeed)] == false) data->player->posY += data->player->dirY * moveSpeed;

// 			// 	// if(worldMap[(int)(data->player->posX + data->player->dirX * moveSpeed)][(int)data->player->posY] == false) data->player->posX += data->player->dirX * moveSpeed;
// 			// 	// if(worldMap[(int)data->player->posY][(int)(data->player->posX + data->player->dirX * moveSpeed)] == false) data->player->posY += data->player->dirY * moveSpeed;
// 			// }
// 			// // //move backwards if no wall behind you
// 			// if(data->player->S == true)
// 			// {
// 			// 	// if(worldMap[(int)(data->player->posY)][(int)(data->player->posX - data->player->dirX * moveSpeed)] == false) data->player->posX += data->player->dirX * moveSpeed;
// 			// 	// if(worldMap[(int)(data->player->posY - data->player->dirY * moveSpeed)][(int)(data->player->posX)] == false) data->player->posY += data->player->dirY * moveSpeed;

// 			// 	if(worldMap[(int)(data->player->posX - data->player->dirX * moveSpeed)][(int)(data->player->posY)] == false) data->player->posX -= data->player->dirX * moveSpeed;
// 			// 	if(worldMap[(int)(data->player->posX)][(int)(data->player->posY - data->player->dirY * moveSpeed)] == false) data->player->posY -= data->player->dirY * moveSpeed;

// 			// 	// if(worldMap[(int)(data->player->posX - data->player->dirX * moveSpeed)][(int)data->player->posY] == false) data->player->posX -= data->player->dirX * moveSpeed;
// 			// 	// if(worldMap[(int)data->player->posY][(int)(data->player->posX - data->player->dirX * moveSpeed)] == false) data->player->posY -= data->player->dirY * moveSpeed;
// 			// }
// 			//calculate ray position and direction
// 			double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
// 			double rayX = data->player->dirX + planeX * cameraX;
// 			double rayY = data->player->dirY + planeY * cameraX;
// 			//which box of the map we're in
// 			int mapX = (int)data->player->posX;
// 			int mapY = (int)data->player->posY;

// 			//length of ray from current position to next x or y-side
// 			double sideDistX;
// 			double sideDistY;

// 			double deltaDistX = (rayX == 0) ? 1e30 : fabs(1 / rayX);
// 			double deltaDistY = (rayY == 0) ? 1e30 : fabs(1 / rayY);

// 			double perpWallDist;

// 			//what direction to step in x or y-direction (either +1 or -1)
// 			int stepX;
// 			int stepY;

// 			int hit = 0; //was there a wall hit?
// 			int side; //was a NS or a EW wall hit?
// 			//calculate step and initial sideDist
// 			if(rayX < 0)
// 			{
// 				stepX = -1;
// 				sideDistX = (data->player->posX - mapX) * deltaDistX;
// 			}
// 			else 
// 			{
// 				stepX = 1;
// 				sideDistX = (mapX + 1.0 - data->player->posX) * deltaDistX;
// 			}
// 			if(rayY < 0)
// 			{
// 				stepY = -1;
// 				sideDistY = (data->player->posY - mapY) * deltaDistY;
// 			}
// 			else
// 			{
// 				stepY = 1;
// 				sideDistY = (mapY + 1.0 - data->player->posY) * deltaDistY;
// 			}
// 			//perform DDA
// 			while(hit == 0)
// 			{
// 			//jump to next map square, either in x-direction, or in y-direction
// 				if(sideDistX < sideDistY)
// 				{
// 					sideDistX += deltaDistX;
// 					mapX += stepX;
// 					side = 0;
// 				}
// 				else
// 				{
// 					sideDistY += deltaDistY;
// 					mapY += stepY;
// 					side = 1;
// 				}
// 			//Check if ray has hit a wall
// 				if(worldMap[mapX][mapY] == '1')
// 				{
// 					hit = 1;
// 				}
// 			}
// 			if(side == 0) perpWallDist = (sideDistX - deltaDistX);
// 			else          perpWallDist = (sideDistY - deltaDistY);  

// 			//Calculate height of line to draw on screen
// 			int lineHeight = (int)(screenHeight / perpWallDist);
			
// 			//calculate lowest and highest pixel to fill in current stripe
// 			int drawStart = -lineHeight / 2 + screenHeight / 2;
// 			if(drawStart < 0)
// 				drawStart = 0;
// 			int drawEnd = lineHeight / 2 + screenHeight / 2;
// 			if(drawEnd >= screenHeight)
// 				drawEnd = screenHeight - 1;
// 			if (drawEnd < 0)
// 				drawEnd = 0;
// 			// printf("%d %d\n", drawStart, drawEnd);
// 			// printf("$$$$$ %d %d %d\n", x, drawEnd, drawStart);
// 			//give x and y sides different brightness
// 			int color = 48705;
// 			if (side == 1) {color = color / 2;}
// 			//draw the pixels of the stripe as a vertical line
// 			int z = drawStart;
// 			// printf("%d %d %d\n", drawStart, drawEnd, x);
// 			// printf("@  %d\n", drawStart);
// 			while (drawStart < drawEnd)
// 			{
// 				my_mlx_pixel_put2(data->win, x, drawStart, color); //
// 				drawStart++;
// 			}
// 			int b = 0;
// 			while (b != z)
// 			{
// 				my_mlx_pixel_put2(data->win, x, b, 16777215);
// 				b++;
// 			}
// 			b = drawEnd;
// 			while (b != screenHeight)
// 			{
// 				my_mlx_pixel_put2(data->win, x, b, 16776960);
// 				b++;
// 			}
// 			x++;
// 		}
// 		// printf("%d %d\n", )
// 		mlx_put_image_to_window(data->win->mlx, data->win->win, data->win->img, 0, 0);

// 		return 1;
// 	// }
// }

// // void ft_gamee(t_data *data)
// // {
// // 	int x, y;

// // 	x = data->player->x;
// // 	y = data->player->y;
// // 	if (data->player->W == true && worldMap[(int)(data->player->y - 1)][(int)data->player->x] != '1')
// // 		data->player->y--;
// // 	else if (data->player->A == true && worldMap[(int)data->player->y][(int)(data->player->x - 1)] != '1')
// // 		data->player->x--;
// // 	else if (data->player->S == true && worldMap[(int)data->player->y + 1][(int)data->player->x] != '1')
// // 		data->player->y++;
// // 	if (data->player->D == true && worldMap[(int)data->player->y][(int)(data->player->x + 1)] != '1')
// // 		data->player->x++;
// // 	if (data->player->x != x || data->player->y != y)
// // 		foo(data);

// // }

// int	key(int keycode, t_data *data)
// {
// 	data->player->W = false;
// 	data->player->A = false;
// 	data->player->S = false;
// 	data->player->D = false;
// 	if (keycode == KEY_W)
// 		data->player->W = true;
// 	if (keycode == KEY_A)
// 		data->player->A = true;
// 	if (keycode == KEY_S)
// 		data->player->S = true;
// 	if (keycode == KEY_D)
// 		data->player->D = true;
// 	// printf("!!  %d\n", keycode);
// 	// if (data->player->W == true || data->player->A == true || data->player->S == true || data->player->D == true)
// 	// ft_gamee(data);
// 	foo(data);
// 	return 1;
// }

// void nazvanie_pridumayu_potom(t_data *data)
// {
// 	data->player->dirX = -1;
// 	data->player->dirY = 0;
// 	data->player->x = 22;
// 	data->player->y = 12;
// 	foo(data);
// 	mlx_hook(data->win->win, 2, 0, &key, data);
// 	// mlx_loop_hook(data->win->win, &foo, data);
// }
