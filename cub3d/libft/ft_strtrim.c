/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:41:49 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/21 18:41:33 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test(char c, char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while ((s1[i]) && ft_test(s1[i], set))
		i++;
	while ((j > i) && ft_test(s1[j - 1], set))
		j --;
	k = 0;
	res = (char *)malloc(sizeof(*s1) * (j - i + 1));
	if (!res)
		return (NULL);
	while (i < j)
	{
		res[k] = s1[i];
		k++;
		i++;
	}
	res[k] = '\0';
	return (res);
}
