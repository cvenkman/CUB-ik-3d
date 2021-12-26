/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:10:45 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/20 21:19:32 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = lst;
	if (tmp == NULL)
		return (0);
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
