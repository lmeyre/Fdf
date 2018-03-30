/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:55:17 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 23:56:50 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long long	ft_power(long long n, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return ((long long)1);
	else if (power == 1)
		return (n);
	return (n * ft_power(n, power - 1));
}
