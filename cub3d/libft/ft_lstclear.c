/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:04:00 by rloyce            #+#    #+#             */
/*   Updated: 2021/04/20 22:36:15 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*beg;

	tmp = *lst;
	while (tmp->next)
	{
		beg = tmp;
		tmp = tmp->next;
		del(beg->content);
		free(beg);
	}
	del(tmp->content);
	free(tmp);
	*lst = NULL;
}
