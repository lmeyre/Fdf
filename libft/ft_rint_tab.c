/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rint_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 23:27:42 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/30 20:50:01 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_rint_tab(int **tab, int nbr_of_tab, int lenght)
{
	int i;
	int j;

	if (!tab || lenght == 0 || nbr_of_tab == 0)
		return ;
	i = 0;
	j = 0;
	while (i < nbr_of_tab)
	{
		while (j < lenght)
		{
			ft_putnbr(tab[i][j]);
			++j;
			if (j < lenght)
				ft_putstr("|");
		}
		ft_putchar('\n');
		j = 0;
		++i;
	}
}
