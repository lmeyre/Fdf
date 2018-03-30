/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:46 by lmeyre            #+#    #+#             */
/*   Updated: 2017/12/08 19:23:27 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ptr;

	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = ft_strnew(i)))
		return (NULL);
	if (!(ptr = ft_strcpy(ptr, s1)))
		return (NULL);
	if (!(ptr = ft_strcat(ptr, s2)))
		return (NULL);
	return (ptr);
}
