/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:39:06 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/19 13:42:49 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*cal;
	unsigned int	n;

	n = num * size;
	cal = malloc(n);
	if (cal)
		ft_memset(cal, 0, n);
	return (cal);
}
