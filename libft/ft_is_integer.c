/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:17:21 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 18:18:42 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		verif_integer(int i, char *str)
{
	if (str[i] < '7' && str[i] >= '0')
		return (1);
	++i;
	if (str[i] < '4' && str[i] >= '0')
		return (1);
	++i;
	if (str[i] < '8' && str[i] >= '0')
		return (1);
	++i;
	if (str[i] < '3' && str[i] >= '0')
		return (1);
	++i;
	if (str[i] < '6' && str[i] >= '0')
		return (1);
	++i;
	if (str[i] < '4' && str[i] >= '0')
		return (1);
	++i;
	if ((str[i] <= '7' && str[i] >= '0')
	|| (str[i] == '8' && str[0] == '-'))
		return (1);
	++i;
	return (0);
}

int				ft_is_integer(char *str)
{
	int i;

	i = ft_strlen(str);
	str[0] == '-' ? --i : 0;
	if (i > 10)
		return (0);
	else if (i < 10)
		return (1);
	else
	{
		i = 0;
		(str[0] == '-') ? ++i : 0;
		if (str[i] < '2' && str[i] >= '0')
			return (1);
		++i;
		if (str[i] < '1' && str[i] >= '0')
			return (1);
		++i;
		if (str[i] < '4' && str[i] >= '0')
			return (1);
		++i;
		return (verif_integer(i, str));
	}
}
