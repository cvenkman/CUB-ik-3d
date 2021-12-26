/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:25:32 by rloyce            #+#    #+#             */
/*   Updated: 2021/12/26 20:14:33 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	color_help2(char c1, char c2)
{
	if (ft_isdigit(c1) && (c2 == ' ' || c2 == ',' || c2 == '\0'))
		return (1);
	return (0);
}

void	color_help(char	*str)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (str[++i] != ',')
		k += color_help2(str[i], str[i + 1]);
	if (k != 1)
		color_error();
	while (str[++i] != ',')
		k += color_help2(str[i], str[i + 1]);
	if (k != 2)
		color_error();
	i++;
	while (str[i])
	{
		k += color_help2(str[i], str[i + 1]);
		i++;
	}
	if (k != 3)
		color_error();
}

void	color_free(t_data *data, char **str, int k)
{
	if (ft_atoi(str[0]) > 255 || ft_atoi(str[1]) > 255 || ft_atoi(str[2]) > 255)
		color_error();
	if (k == 1)
	{
		data->floor[0] = ft_atoi(str[0]);
		data->floor[1] = ft_atoi(str[1]);
		data->floor[2] = ft_atoi(str[2]);
		free(data->fl);
		data->fl = NULL;
	}
	else
	{
		data->ceil[0] = ft_atoi(str[0]);
		data->ceil[1] = ft_atoi(str[1]);
		data->ceil[2] = ft_atoi(str[2]);
		free(data->cl);
		data->cl = NULL;
	}
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str);
}

void	parse_color_ceil(t_data *data)
{
	int		i;
	int		z;
	char	**tmp;

	i = 0;
	z = 0;
	while (data->cl[i])
	{
		if (data->cl[i] != ',' && data->cl[i] != ' '
			&& (data->cl[i] < '0' || data->cl[i] > '9'))
			color_error();
		if (data->cl[i] == ',')
			z++;
		i++;
	}
	if (z != 2)
		color_error();
	color_help(data->cl);
	data->cl = remove_space(data->cl);
	tmp = ft_split(data->cl, ',');
	if (!tmp)
		malloc_error();
	color_free(data, tmp, 0);
}

void	parse_color(t_data *data)
{
	int		i;
	int		z;
	char	**tmp;

	i = 0;
	z = 0;
	while (data->fl[i])
	{
		if (data->fl[i] != ',' && data->fl[i] != ' '
			&& (data->fl[i] < '0' || data->fl[i] > '9'))
			color_error();
		if (data->fl[i] == ',')
			z++;
		i++;
	}
	if (z != 2)
		color_error();
	color_help(data->fl);
	data->fl = remove_space(data->fl);
	tmp = ft_split(data->fl, ',');
	if (!tmp)
		malloc_error();
	color_free(data, tmp, 1);
	parse_color_ceil(data);
}
