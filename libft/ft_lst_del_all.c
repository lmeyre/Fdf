/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:22:34 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 18:28:21 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lst_del_all(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	while ((*lst)->next)
		*lst = (*lst)->next;
	while (*lst)
	{
		if ((*lst)->content)
			free((*lst)->content);
		(*lst)->content = NULL;
		if (!((*lst)->prev))
			break ;
		*lst = (*lst)->prev;
		free((*lst)->next);
	}
	free(*lst);
}
