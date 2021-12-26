/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:31:10 by rloyce            #+#    #+#             */
/*   Updated: 2021/12/26 20:14:11 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*remove_space(char	*str)
{
	int		i;
	int		k;
	char	*tmp;

	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] != ' ')
			k++;
	tmp = (char *)malloc(sizeof(char) * (k + 1));
	if (!tmp)
		malloc_error();
	i = -1;
	k = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
		{
			tmp[k] = str[i];
			k++;
		}
	}
	tmp[k] = '\0';
	free(str);
	return (tmp);
}

int	str_is_empty(char *str)
{
	if (str == NULL)
		return (1);
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (1);
	}
	return (0);
}

char	*list_to_string(char *content)
{
	char	*str;

	str = ft_strdup(content);
	if (!str)
		malloc_error();
	return (str);
}

void	ft_lst_free(t_list **lst)
{
	t_list	*tmp;
	t_list	*beg;

	tmp = *lst;
	while (tmp->next)
	{
		beg = tmp;
		tmp = tmp->next;
		if (beg->content != NULL)
			free(beg->content);
		if (beg != NULL)
			free(beg);
	}
	if (tmp->content != NULL)
		free(tmp->content);
	if (tmp != NULL)
		free(tmp);
	*lst = NULL;
}
