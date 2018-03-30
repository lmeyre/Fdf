/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:08:20 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 20:49:58 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int size;
	int *array;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	if (!(array = (int*)malloc(sizeof(int) * (size))))
		return (0);
	ft_bzero(array, sizeof(int) * (size));
	while (i < size)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}
