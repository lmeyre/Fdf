/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:23:59 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 00:57:55 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*s1bis;
	const unsigned char		*s2bis;

	if (!(s1) && !(s2))
		return (0);
	s1bis = s1;
	s2bis = s2;
	if (!(s1))
		return ((int)s2bis[0]);
	if (!(s2))
		return ((int)s1bis[0]);
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1bis[i] != s2bis[i])
			return (s1bis[i] - s2bis[i]);
		i++;
	}
	i--;
	return (s1bis[i] - s2bis[i]);
}
