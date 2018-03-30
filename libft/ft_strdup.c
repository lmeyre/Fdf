/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:25:57 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 01:07:51 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	if (!(s2 = (char*)ft_memalloc(sizeof(char) * (1 + i))))
		return (0);
	s2[i] = '\0';
	while (i >= 0)
	{
		s2[i] = s1[i];
		i--;
	}
	return (s2);
}
