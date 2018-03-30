/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:13:12 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/23 00:13:18 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_lst_add(t_list **alst, t_list *mew)
{
	t_list *tmp;

	if (!(alst) || !(mew) || !(*alst))
		return (0);
	tmp = *alst;
	*alst = mew;
	mew->next = tmp;
	tmp->prev = *alst;
	return (1);
}
