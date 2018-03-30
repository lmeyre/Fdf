/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:29:25 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/13 23:38:12 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = (void*)malloc(sizeof(void) * (size))))
		return (0);
	ft_bzero(ptr, size);
	return (ptr);
}
