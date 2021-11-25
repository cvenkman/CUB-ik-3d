/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:40:15 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/21 14:27:30 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*adest;
	unsigned char	*asrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	adest = (unsigned char *)dest;
	asrc = (unsigned char *)src;
	i = 0;
	if (asrc < adest)
	{
		while (n-- > 0)
			adest[n] = asrc[n];
	}
	else
	{
		while (i < n)
		{
			adest[i] = asrc[i];
			i++;
		}
	}
	return (dest);
}
