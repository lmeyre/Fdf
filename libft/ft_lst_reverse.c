/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:26:55 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 18:27:06 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lst_reverse(t_list *lst)
{
	t_list *tmpnext;

	if (!lst)
		return (NULL);
	while (lst)
	{
		tmpnext = lst->next;
		lst->next = lst->prev;
		lst->prev = tmpnext;
		if (tmpnext)
			lst = tmpnext;
		else
			return (lst);
	}
	return (NULL);
}
