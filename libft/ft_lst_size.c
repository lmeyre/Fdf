/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:11:06 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 18:27:21 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_lst_size(t_list *lst)
{
	int		count;
	t_list	*tmp;

	count = 0;
	if (!lst)
		return (count);
	tmp = lst;
	while (tmp)
	{
		++count;
		tmp = tmp->next;
	}
	return (count);
}
