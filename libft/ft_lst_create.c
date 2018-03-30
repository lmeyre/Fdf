/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:59:08 by lmeyre            #+#    #+#             */
/*   Updated: 2018/02/18 11:47:23 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_create_lst(int size, int content_size)
{
	t_list	*start;
	t_list	*curr;
	t_list	*prev;

	start = ft_lst_new(content_size);
	curr = start;
	prev = NULL;
	while (size > 1)
	{
		curr->next = ft_lst_new(content_size);
		curr->prev = prev;
		prev = curr;
		curr = curr->next;
		--size;
	}
	curr->prev = prev;
	return (start);
}
