/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:58:23 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/28 18:38:14 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	**ft_2d_array(int width, int height, int size_type)
{
	void	**array;
	int		count;

	if (width == 0 || height == 0 || size_type <= 0)
		return (NULL);
	count = 0;
	if (!(array = (void**)malloc(sizeof(void*) * (width + 1))))
		return (NULL);
	while (count <= width)
	{
		if (!(array[count] = (void*)malloc(size_type * (height + 1))))
			return (NULL);
		ft_bzero(array[count], (size_type * (height + 1)));
		count++;
	}
	array[count] = NULL;
	return (array);

}
