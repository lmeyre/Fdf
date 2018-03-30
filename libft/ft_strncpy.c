/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:27:33 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 01:11:16 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	i = 0;
	while (*src && (i < len))
	{
		dest[i++] = *src++;
	}
	while (i < len)
	{
		dest[i++] = '\0';
	}
	return (dest);
}
