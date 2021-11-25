/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:21:24 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/19 13:51:56 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*adest;
	unsigned char	*asrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	adest = (unsigned char *)dest;
	asrc = (unsigned char *)src;
	while (i < n)
	{
		adest[i] = asrc[i];
		i++;
	}
	return (adest);
}
