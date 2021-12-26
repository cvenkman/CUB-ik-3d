/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:40:03 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/20 15:50:09 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_plus(int n, int len)
{
	char	*resp;

	resp = (char *)malloc(len + 1);
	if (!resp)
		return (NULL);
	resp[len] = '\0';
	len--;
	while (len >= 0)
	{
		resp[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (resp);
}

static char	*ft_minus(int n, int len)
{
	char	*resm;

	resm = (char *)malloc(len + 2);
	if (!resm)
		return (NULL);
	resm[0] = '-';
	resm[len + 1] = '\0';
	while (len > 0)
	{
		resm[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (resm);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	if (n >= 0)
		res = ft_plus(n, len);
	else
		res = ft_minus(-n, len);
	return (res);
}
