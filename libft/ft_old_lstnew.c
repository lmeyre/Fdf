/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_old_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:29:59 by lmeyre            #+#    #+#             */
/*   Updated: 2017/12/13 18:52:04 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list*ptr;

	if (!(ptr = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		ptr->content = NULL;
	}
	else
	{
		ptr->content = ft_memalloc(content_size);
		ptr->content = ft_memmove(ptr->content, content, content_size);
	}
	ptr->next = NULL;
	return (ptr);
}
