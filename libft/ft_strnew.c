/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:57:45 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 01:11:37 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_bzero(ptr, size + 1);
	return (ptr);
}
