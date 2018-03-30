/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:22:19 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 21:10:45 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_sort_params(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		return ;
	while ((i <= argc - 2))
	{
		if (ft_strcmp(argv[i + 1], argv[i]) == -1)
		{
			ft_swap_str(argv[i + 1], argv[i]);
			i = 0;
		}
		i++;
	}
	i = 1;
	while (i <= argc - 1)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}
