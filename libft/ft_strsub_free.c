/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:47:33 by lmeyre            #+#    #+#             */
/*   Updated: 2017/12/14 23:35:01 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub_free(char const *s,
		unsigned int start, size_t len, char **out)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	if (!(s))
		return (ptr);
	i = 0;
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	while (len > 0)
	{
		ptr[i] = s[start];
		i++;
		len--;
		start++;
	}
	if (*out)
		ft_strdel(out);
	return (ptr);
}
