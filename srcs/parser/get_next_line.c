/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 00:30:35 by rloyce            #+#    #+#             */
/*   Updated: 2021/12/26 20:14:22 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	error_free(char *remain, char *buf, int i)
{
	if (remain != NULL)
	{
		free(remain);
		remain = NULL;
	}
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
	return (i);
}

int	check_n(char **remain, char **line)
{
	char	*pointer;

	pointer = ft_strchr(*remain, '\n');
	if (pointer)
	{
		*pointer = '\0';
		*line = ft_strdup(*remain);
		if (!(*line))
		{
			free(remain);
			remain = NULL;
			return (-1);
		}
		ft_strcpy(*remain, ++pointer);
		if (!(*remain))
		{
			free(remain);
			remain = NULL;
			return (-1);
		}	
		return (1);
	}
	return (0);
}

int	rest2(char **remain, char **line)
{
	if (check_n(&(*remain), line) == 1)
		return (1);
	*line = ft_strdup(*remain);
	if (!(*line))
		return (error_free(*remain, NULL, -1));
	free(*remain);
	*remain = NULL;
	return (0);
}

int	rest(char **remain, char **line, char *buf, int fd)
{
	int		l;
	int		k;
	int		byte_readed;
	char	*temp;

	byte_readed = read(fd, buf, BUFFER_SIZE);
	while (byte_readed)
	{
		buf[byte_readed] = '\0';
		temp = *remain;
		*remain = ft_strjoin(*remain, buf);
		free(temp);
		if (!(*remain))
			return (error_free(*remain, buf, -1));
		l = check_n(&(*remain), line);
		if (l == 1)
			return (error_free(NULL, buf, 1));
		else if (l == -1)
			return (error_free(*remain, buf, -1));
		byte_readed = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	k = rest2(remain, line);
	return (k);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*remain;
	int			k;

	if (BUFFER_SIZE < 1 || !line || fd < 0 || (read(fd, 0, 0) < 0))
		return (-1);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	if (!remain)
		remain = ft_strdup("");
	k = rest(&remain, line, buf, fd);
	return (k);
}
