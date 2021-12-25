/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:28:35 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/29 11:15:52 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr (const char *str, int ch)
{
	size_t	i;
	size_t	k;

	i = ft_strlen(str);
	k = 0;
	while (i >= k)
	{
		if (str[i - k] == (char)ch)
			return ((char *)&str[i - k]);
		k++;
	}
	return (NULL);
}
