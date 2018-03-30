/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:22:22 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 19:23:36 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lst_del_one(t_list **lst, int position)
{
	t_list	*over;

	over = NULL;
	if (!lst || !(*lst))
		return (NULL);
	while (position > 1)
	{
		*lst = (*lst)->next;
		--position;
		if (!*lst)
			return (NULL);
	}
	((*lst)->prev) ? ((*lst)->prev)->next = (*lst)->next : 0;
	((*lst)->next) ? ((*lst)->next)->prev = (*lst)->prev : 0;
	if ((*lst)->prev)
		over = (*lst)->prev;
	else if ((*lst)->next)
		over = (*lst)->next;
	((*lst)->content) ? free((*lst)->content) : 0;
	free(*lst);
	*lst = NULL;
	if (over != NULL)
		while (over->prev)
			over = over->prev;
	return (over);
}
