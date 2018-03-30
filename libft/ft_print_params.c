/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:59:29 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 21:04:52 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_print_params(int argc, char **argv)
{
	int i;

	if (!argv)
		return ;
	i = 1;
	while (argc > i)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}
