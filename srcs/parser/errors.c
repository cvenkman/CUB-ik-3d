/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:15:47 by rloyce            #+#    #+#             */
/*   Updated: 2021/12/26 20:14:29 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	first_errors(int k)
{
	if (k == 1)
		ft_putstr_fd("Arguments Error!\n", STD_ERR);
	if (k == 2)
		ft_putstr_fd("Wrong file format!\n", STD_ERR);
	if (k == 3)
		ft_putstr_fd("Use file instead of a directory!\n", STD_ERR);
	if (k == 4)
		ft_putstr_fd("Description file does not exist or use chmod!\n", STD_ERR);
	exit(0);
}

void	type_error(void)
{
	ft_putstr_fd("Type identifier error\n", STD_ERR);
	exit(0);
}

void	malloc_error(void)
{
	ft_putstr_fd("Malloc error\n", STD_ERR);
	exit(0);
}

void	map_error(void)
{
	ft_putstr_fd("Map error\n", STD_ERR);
	exit(0);
}

void	color_error(void)
{
	ft_putstr_fd("Colour error\n", STD_ERR);
	exit(0);
}
