/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:56:04 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 23:56:07 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putlong_unsigned(unsigned long long n)
{
	if (n > 9)
	{
		ft_putlong_unsigned(n / 10);
		ft_putlong_unsigned(n % 10);
	}
	else
		ft_putchar(n + '0');
}
