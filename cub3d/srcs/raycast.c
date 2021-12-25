#include "../cub3d.h"
void		ft_step(t_player *player);
void		check_hit(t_player *player);
int			raycasting(t_player *player);
void		image_to_image_cp(t_win *dst, t_win *src, t_point position);
t_point		point_set(int x, int y);
void		pixel_put(t_win *img, t_point	p, unsigned int colour);
size_t		pixel_get(t_win *img, t_point p);


void start_raycasting(t_data *data)
{
	mlx_loop_hook(data->win->mlx, (void *)raycasting, data->player);
	mlx_hook(data->win->win, 2, 0, &key, data->player);
	mlx_loop(data->win->mlx);
}

int raycasting(t_player *player)
{
	int x = 0;
	double cameraX;
	while (x < SCREEN_W)
	{
		//calculate ray position and direction
		cameraX = 2 * x / (double)SCREEN_W - 1; //x-coordinate in camera space
		player->ray_dir_x = player->dir_x + player->plane_x * cameraX;
		player->ray_dir_y = player->dir_y + player->plane_y * cameraX;
		
		player->delta_dist_x = fabs(1 / player->ray_dir_x);
		player->delta_dist_y = fabs(1 / player->ray_dir_y);

		// player->delta_dist_x = sqrt(1 + (player->ray_dir_y * player->ray_dir_y)
		// 		/ (player->ray_dir_x * player->ray_dir_x));
		// player->delta_dist_y = sqrt(1 + (player->ray_dir_x * player->ray_dir_x)
		// 		/ (player->ray_dir_y * player->ray_dir_y));
		// double perp_wall_dist;
	
		player->map_x = (int)player->x;
		player->map_y = (int)player->y;
		ft_step(player);
		check_hit(player);

		// if(player->side == 0)
		// 	player->perp_wall_dist = (player->side_dist_x - player->delta_dist_x);
		// else
		// 	player->perp_wall_dist = (player->side_dist_y - player->delta_dist_y);

		if (player->side == 0)
			player->perp_wall_dist = (player->map_x - player->x
					+ (1 - player->step_x) / 2) / player->ray_dir_x;
		else
			player->perp_wall_dist = (player->map_y - player->y
					+ (1 - player->step_y) / 2) / player->ray_dir_y;

		//Calculate height of line to draw on screen
		player->line_height = (int)(SCREEN_H / player->perp_wall_dist);
		//calculate lowest and highest pixel to fill in current stripe
		player->draw_start = -player->line_height / 2 + SCREEN_H / 2;
		if (player->draw_start < 0)
			player->draw_start = 0;
		// if (player->draw_start > SCREEN_H)
		// 	player->draw_start = SCREEN_H - 1;
		player->draw_end = player->line_height / 2 + SCREEN_H / 2;
		if (player->draw_end > SCREEN_H)
			player->draw_end = SCREEN_H - 1;
		// if (player->draw_end < 0)
		// 	player->draw_end = SCREEN_H - 1;

		if (player->side == 0)
			player->wall_x = player->y + player->perp_wall_dist * player->ray_dir_y;
		else
			player->wall_x = player->x + player->perp_wall_dist * player->ray_dir_x;
		player->wall_x -= floor((player->wall_x));

		player->tex_x = (int)(player->wall_x * (double)TEX_WIDTH);
		if (player->side == 0 && player->ray_dir_x > 0)
			player->tex_x = TEX_WIDTH - player->tex_x - 1;
		if (player->side == 1 && player->ray_dir_y < 0) // ?? same
			player->tex_x = TEX_WIDTH - player->tex_x - 1;

		player->step = 1.0 * TEX_HEIGHT / player->line_height;
		player->tex_pos = (player->draw_start - SCREEN_H
				/ 2 + player->line_height / 2) * player->step;
		int color = 48705;

		if (player->side == 1)
			color = color / 2;
		draw_verLine(player->data->win, x, player->draw_start, player->draw_end, player->data, color);
		x++;
	}
	image_to_image_cp(player->data->win, &player->data->img_map, point_set(0, 0));
	mlx_put_image_to_window(player->data->win->mlx, player->data->win->win, player->data->win->img, 0, 0);
	return 1;
}

void ft_step(t_player *player)
{
	if(player->ray_dir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->x - player->map_x) * player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1.0 - player->x) * player->delta_dist_x;
	}
	if(player->ray_dir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->y - player->map_y) * player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1.0 - player->y) * player->delta_dist_y;
	}
}

void check_hit(t_player *player)
{
	int hit = 0;

	while(hit == 0)
	{
		if(player->side_dist_x < player->side_dist_y)
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

// void	map_fill_img(t_win img_map, char **maps)
// {
// 	t_point	point;
// 	t_point	in_pix_coord;
// 	int		size_block;
// 	int		maxyx;

// 	point.x = 0;
// 	fill_big_pixel(img_map, point, 9999, 0x0);
// 	maxyx = img_map.size_img.x;
// 	if (img_map.size_img.y > img_map.size_img.x)
// 		maxyx = img_map.size_img.y;
// 	size_block = maxyx / vlen_map(maps);
// 	point.y = -1;
// 	while (maps[++point.y])
// 	{
// 		point.x = -1;
// 		while (maps[point.y][++point.x])
// 		{
// 			if (maps[point.y][point.x] == '1')
// 			{
// 				in_pix_coord.x = point.x * size_block;
// 				in_pix_coord.y = point.y * size_block;
// 				fill_big_pixel(img_map, in_pix_coord, size_block, 0x00552233);
// 			}
// 		}
// 	}
// }
// закрашиваю один пиксель на изображении
void	image_to_image_cp(t_win *dst, t_win *src, t_point position)
{
	t_point	i;
	t_point	tmp;
	int		color;

	i.y = -1;
	i.x = -1;
	while (++i.y < src->size_img.y)
	{
		while (++i.x < src->size_img.x)
		{
			tmp.x = i.x + position.x;
			tmp.y = i.y + position.y;
			color = pixel_get(src, i);
			if (color == 0x0)
				continue ;
			pixel_put(dst, tmp, color);
		}
		i.x = -1;
	}
}

t_point	point_set(int x, int y)
{
	t_point	pnt;

	pnt.x = x;
	pnt.y = y;
	return (pnt);
}

void	pixel_put(t_win *img, t_point	p, unsigned int colour)
{
	char	*dst;

	if (p.x < 0 || p.x >= img->size_img.x || p.y < 0 || p.y >= img->size_img.y)
		return ;
	dst = img->addr + ((p.y * img->line_length) + (p.x * (img->bits_per_pixel / 8)));
	*(unsigned int *)dst = colour;
}

// Получаю пиксель из изображения
size_t	pixel_get(t_win *img, t_point p)
{
	void			*dst;
	unsigned int	ret;

	if (p.x < 0 || p.x >= img->size_img.x || p.y < 0 || p.y >= img->size_img.y)
		return (0xFF000000);
	dst = img->addr + ((p.y * img->line_length) + (p.x * (img->bits_per_pixel / 8)));
	ret = *(unsigned int *)dst;
	return (ret);
}
