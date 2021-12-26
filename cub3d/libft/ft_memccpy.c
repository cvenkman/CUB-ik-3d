/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:30:52 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/21 14:17:59 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*adest;
	unsigned char	*asrc;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	adest = (unsigned char *)dest;
	asrc = (unsigned char *)src;
	while (i < n)
	{
		adest[i] = asrc[i];
		if (adest[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
