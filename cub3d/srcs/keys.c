#include "../cub3d.h"

static void key_w(t_player *player)
{
	if (player->data->map[(int)(player->x + player->dir_x * SPEED)][(int)(player->y)] == '0')
		player->x += player->dir_x * SPEED;
	if (player->data->map[(int)(player->x)][(int)(player->y + player->dir_y * SPEED)] == '0')
		player->y += player->dir_y * SPEED;
}

static void key_a(t_player *player)
{
	if (player->data->map[(int)(player->x - player->plane_x * SPEED)][(int)(player->y)] == '0')
		player->x -= player->plane_x * SPEED;
	if (player->data->map[(int)(player->x)][(int)(player->y - player->plane_y * SPEED)] == '0')
		player->y -= player->plane_y * SPEED;
}

static void key_s(t_player *player)
{
	if (player->data->map[(int)(player->x - player->dir_x * SPEED)][(int)(player->y)] == '0')
		player->x -= player->dir_x * SPEED;
	if (player->data->map[(int)(player->x)][(int)(player->y - player->dir_x * SPEED)] == '0')
		player->y -= player->dir_y * SPEED;
}

static void key_d(t_player *player)
{
	if (player->data->map[(int)(player->x + player->plane_x * SPEED)][(int)(player->y)] == '0')
		player->x += player->plane_x * SPEED;
	if (player->data->map[(int)(player->x)][(int)(player->y + player->plane_y * SPEED)] == '0')
		player->y += player->plane_y * SPEED;
}

static void key_l_arr(t_player *player)
{
	double oldDirX = player->dir_x;
	player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y * sin(ROT_SPEED);
	player->dir_y = oldDirX * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
	double oldPlaneX = player->plane_x;
	player->plane_x = player->plane_x * cos(ROT_SPEED) - player->plane_y * sin(ROT_SPEED);
	player->plane_y = oldPlaneX * sin(ROT_SPEED) + player->plane_y * cos(ROT_SPEED);
}

static void key_r_arr(t_player *player)
{
	//both camera direction and camera plane must be rotated
	double oldDirX = player->dir_x;
	player->dir_x = player->dir_x * cos(-ROT_SPEED) - player->dir_y * sin(-ROT_SPEED);
	player->dir_y = oldDirX * sin(-ROT_SPEED) + player->dir_y * cos(-ROT_SPEED);
	double oldPlaneX = player->plane_x;
	player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y * sin(-ROT_SPEED);
	player->plane_y = oldPlaneX * sin(-ROT_SPEED) + player->plane_y * cos(-ROT_SPEED);
}

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
    if(keycode == KEY_ARR_R)
		key_r_arr(player);
    if (keycode == KEY_ARR_L)
		key_l_arr(player);
	if (keycode == 53)
		exit(0);
	printf("%d\n", keycode);
	foo(player);
	return 1;
}
