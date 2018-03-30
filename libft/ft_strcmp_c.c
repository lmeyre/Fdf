/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 23:47:24 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 18:22:07 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strcmp_c(const char *s1, const char *s2, char c)
{
	if (!c)
		return (0);
	while (*s1 && *s2)
	{
		if (*s1 == c || *s2 == c)
		{
			s1--;
			s2--;
			break ;
		}
		if ((*s1 - *s2) != 0)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
