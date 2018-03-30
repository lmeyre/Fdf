/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:21:24 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/22 00:28:18 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int k;
	int boul;

	if (!(str))
		return (0);
	boul = 0;
	k = 0;
	i = 0;
	while (str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		str[i] == '-' ? boul = -1 : boul;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10) + (str[i] - '0');
		i++;
	}
	if (boul == -1)
		k = k * -1;
	return (k);
}
