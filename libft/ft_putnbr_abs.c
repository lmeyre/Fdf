/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_abs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:57:02 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 23:57:12 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_abs(long long int n)
{
	if (n == LONG_MIN)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	else if (n < 0)
		n = n * -1;
	if (n > 9)
	{
		ft_putnbr_abs(n / 10);
		ft_putnbr_abs(n % 10);
	}
	else
		ft_putchar(n + '0');
}
