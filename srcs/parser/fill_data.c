/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:28:44 by rloyce            #+#    #+#             */
/*   Updated: 2021/12/26 20:14:25 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_data(t_data *data)
{
	data->way_to_file_so = NULL;
	data->way_to_file_no = NULL;
	data->way_to_file_we = NULL;
	data->way_to_file_ea = NULL;
	data->fl = NULL;
	data->cl = NULL;
	data->player_dir = '0';
	data->player_pos[0] = 0;
	data->player_pos[1] = 0;
}

void	fill_data_f(t_data *data, char *content, int i)
{
	i++;
	while (content[i] == ' ')
		i++;
	data->fl = ft_strdup((content + i));
}

void	fill_data_c(t_data *data, char *content, int i)
{
	i++;
	while (content[i] == ' ')
		i++;
	data->cl = ft_strdup((content + i));
}

void	fill_data(t_data *data, char *content)
{
	int	i;

	i = 0;
	while (content[i] == ' ')
			i++;
	if (content[i] == 'S' && content[i + 1] == 'O' && content[i + 2] == ' '
		&& str_is_empty((char*)data->way_to_file_so))
		fill_data_so(data, content, i);
	else if (content[i] == 'N' && content[i + 1] == 'O' && content[i + 2] == ' '
		&& str_is_empty((char*)data->way_to_file_no))
		fill_data_no(data, content, i);
	else if (content[i] == 'W' && content[i + 1] == 'E' && content[i + 2] == ' '
		&& str_is_empty((char*)data->way_to_file_we))
		fill_data_we(data, content, i);
	else if (content[i] == 'E' && content[i + 1] == 'A' && content[i + 2] == ' '
		&& str_is_empty((char*)data->way_to_file_ea))
		fill_data_ea(data, content, i);
	else if (content[i] == 'F' && content[i + 1] == ' '
		&& str_is_empty((char*)data->fl))
		fill_data_f(data, content, i);
	else if (content[i] == 'C' && content[i + 1] == ' '
		&& str_is_empty((char*)data->cl))
		fill_data_c(data, content, i);
	else
		type_error();
}
