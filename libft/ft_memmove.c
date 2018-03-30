/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:24:20 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 01:01:38 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	size_t				i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	pdest = dst;
	psrc = src;
	if (pdest < psrc)
	{
		while (i < len)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	else if (pdest > psrc)
	{
		while (len--)
		{
			pdest[len] = psrc[len];
		}
	}
	return (dst);
}
