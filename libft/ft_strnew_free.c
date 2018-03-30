/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:14:59 by lmeyre            #+#    #+#             */
/*   Updated: 2017/12/14 23:36:13 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew_free(size_t size, char **str)
{
	char *ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_bzero(ptr, size + 1);
	if (*str)
		ft_strdel(str);
	return (ptr);
}
