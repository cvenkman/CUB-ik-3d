#include "../cub3d.h"

// void key_w(t_player *player)
// {
// 	if (player->data->map[(int)(player->x + player->dir_x * SPEED)][(int)(player->y)] == '0')
// 		player->x += player->dir_x * SPEED;
// 	if (player->data->map[(int)(player->x)][(int)(player->y + player->dir_y * SPEED)] == '0')
// 		player->y += player->dir_y * SPEED;
// }

// void key_a(t_player *player)
// {
// 	if (player->data->map[(int)(player->x - player->plane_x * SPEED)][(int)(player->y)] == '0')
// 		player->x -= player->plane_x * SPEED;
// 	if (player->data->map[(int)(player->x)][(int)(player->y - player->plane_y * SPEED)] == '0')
// 		player->y -= player->plane_y * SPEED;
// }

// void key_s(t_player *player)
// {
// 	if (player->data->map[(int)(player->x - player->dir_x * SPEED)][(int)(player->y)] == '0')
// 		player->x -= player->dir_x * SPEED;
// 	if (player->data->map[(int)(player->x)][(int)(player->y - player->dir_x * SPEED)] == '0')
// 		player->y -= player->dir_y * SPEED;
// }

// void key_d(t_player *player)
// {
// 	if (player->data->map[(int)(player->x + player->plane_x * SPEED)][(int)(player->y)] == '0')
// 		player->x += player->plane_x * SPEED;
// 	if (player->data->map[(int)(player->x)][(int)(player->y + player->plane_y * SPEED)] == '0')
// 		player->y += player->plane_y * SPEED;
// }

void key_w(t_player *player)
{
	if (player->data->map[(int)(player->x + player->dir_x * SPEED)][(int)(player->y)] == '0')
		player->x += player->dir_x * SPEED;
	if (player->data->map[(int)(player->x)][(int)(player->y + player->dir_y * SPEED)] == '0')
		player->y += player->dir_y * SPEED;
}

void key_s(t_player *player)
{
	if (player->data->map[(int)(player->x - player->dir_x * SPEED)][(int)(player->y)] == '0')
		player->x -= player->dir_x * SPEED;
	if (player->data->map[(int)(player->x)][(int)(player->y - player->dir_y * SPEED)] == '0')
		player->y -= player->dir_y * SPEED;
}

void key_d(t_player *player)
{
	if (player->data->map[(int)(player->x + player->dir_y * SPEED)][(int)(player->y)] == '0')
		player->x += player->dir_y * SPEED;
	if (player->data->map[(int)(player->x)][(int)(player->y - player->dir_x * SPEED)] == '0')
		player->y -= player->dir_x * SPEED;
}

void key_a(t_player *player)
{
	if (player->data->map[(int)(player->x - player->dir_y * SPEED)][(int)(player->y)] == '0')
		player->x -= player->dir_y * SPEED;
	if (player->data->map[(int)(player->x)][(int)(player->y + player->dir_x * SPEED)] == '0')
		player->y += player->dir_x * SPEED;
}
