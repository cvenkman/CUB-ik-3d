/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:29:51 by rloyce            #+#    #+#             */
/*   Updated: 2021/12/26 20:14:27 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	fill_data_so(t_data *data, char *content, int i)
{
	i += 2;
	while (content[i] == ' ')
		i++;
	data->way_to_file_so = ft_strdup((content + i));
}

void	fill_data_no(t_data *data, char *content, int i)
{
	i += 2;
	while (content[i] == ' ')
		i++;
	data->way_to_file_no = ft_strdup((content + i));
}

void	fill_data_we(t_data *data, char *content, int i)
{
	i += 2;
	while (content[i] == ' ')
		i++;
	data->way_to_file_we = ft_strdup((content + i));
}

void	fill_data_ea(t_data *data, char *content, int i)
{
	i += 2;
	while (content[i] == ' ')
		i++;
	data->way_to_file_ea = ft_strdup((content + i));
}
