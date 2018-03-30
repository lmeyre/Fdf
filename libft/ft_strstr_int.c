/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:45:38 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/24 17:48:06 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strstr_int(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;

	if (!haystack)
		return (0);
	if (!(needle[0]) || !needle)
		return (0);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		k = i;
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return (1);
		}
		j = 0;
		i = k;
		i++;
	}
	return (0);
}
