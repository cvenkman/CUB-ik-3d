/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:50:15 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/19 17:25:08 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	s = 0;
	i = 0;
	while (dst[i] && (i < size))
		i++;
	while (((s + i + 1) < size) && src[s])
	{
		dst[i + s] = src[s];
		s++;
	}
	if (i < size)
		dst[i + s] = '\0';
	return (i + ft_strlen(src));
}
