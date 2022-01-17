/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:00:23 by cvenkman          #+#    #+#             */
/*   Updated: 2022/01/17 19:28:01 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void			get_color_texure(t_data *data,
						int ***color, char *way_to_file);
static unsigned int	get_pixel_color(t_win *img, int i, int j);
static void			error_exit(char *str);

void	init_texture(t_data *data)
{
	get_color_texure(data, &data->texture->north, data->way_to_file_no);
	get_color_texure(data, &data->texture->south, data->way_to_file_so);
	get_color_texure(data, &data->texture->west, data->way_to_file_we);
	get_color_texure(data, &data->texture->east, data->way_to_file_ea);
}

static void	get_color_texure(t_data *data, int ***color, char *way_to_file)
{
	int		width;
	int		h;
	int		i;
	int		j;
	t_win	img;

	i = 0;
	img.img = mlx_xpm_file_to_image(data->win->mlx, way_to_file, &width, &h);
	if (!img.img)
		error_exit("img error with textures");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	(*color) = malloc(sizeof(int *) * width);
	if (!(*color))
		error_exit("malloc error with color");
	while (i < TEX_WIDTH)
	{
		j = -1;
		(*color)[i] = malloc(sizeof(int) * h);
		while (++j < TEX_HEIGHT)
			(*color)[i][j] = get_pixel_color(&img, i, j);
		i++;
	}
}

static unsigned int	get_pixel_color(t_win *img, int i, int j)
{
	char			*adr;
	unsigned int	color;

	adr = img->addr + (j * img->line_length + i * (img->bits_per_pixel / 8));
	color = *(unsigned int *)adr;
	return (color);
}

static void	error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
