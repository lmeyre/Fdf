/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:27:44 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 01:14:08 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	if (!haystack)
		return (NULL);
	if (!(needle[0]) || !needle)
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0' && (i < len))
	{
		k = i;
		while (haystack[i] == needle[j] && (i < len))
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char*)haystack + k);
		}
		j = 0;
		i = k;
		i++;
	}
	return (0);
}
