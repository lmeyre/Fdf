/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:10:03 by lmeyre            #+#    #+#             */
/*   Updated: 2018/02/02 21:45:16 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lst_new(size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	ptr->content = ft_memalloc(content_size);
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
