/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:48:59 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/29 23:01:08 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_error(char **rrr)
{
	size_t	i;

	i = 0;
	while (rrr[i])
	{
		free(rrr[i]);
		i++;
	}
	free(rrr);
	return (NULL);
}

static	size_t	ft_count(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			k++;
		while (s[i] != c && s[i])
			i++;
	}
	return (k);
}

static char	*st(char const *s, char c, size_t k)
{
	char	*r;
	size_t	i;
	size_t	e;

	i = 0;
	e = k;
	while (s[e] && (s[e] != c))
		e++;
	r = (char *)malloc(sizeof(char) * (e - k + 1));
	if (!r)
		return (NULL);
	while (s[k] && s[k] != c)
	{
		r[i] = s[k];
		i++;
		k++;
	}
	r[i] = '\0';
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	res = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
		{
			res[j] = st(s, c, i);
			if (!res[j])
				return (ft_error(res));
			j++;
			while (s[i] && (s[i] != c))
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}
