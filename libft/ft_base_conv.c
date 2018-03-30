/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:42:26 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/12 22:44:00 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_base_conv(char *str, int base_src, int base_dest)
{
	long long	nbr;
	char		*ptr;
	int			i;
	int			index;
	int			tmp;

	index = 0;
	nbr = 0;
	i = ft_strlen(str);
	while (i)
	{
		tmp = 0;
		str[index] == 'A' ? tmp = 10 : 0;
		str[index] == 'B' ? tmp = 11 : 0;
		str[index] == 'C' ? tmp = 12 : 0;
		str[index] == 'D' ? tmp = 13 : 0;
		str[index] == 'E' ? tmp = 14 : 0;
		str[index] == 'F' ? tmp = 15 : 0;
		tmp == 0 ? tmp = str[index] - '0' : 0;
		nbr += tmp * ft_power(base_src, i - 1);
		--i;
		index++;
	}
	ptr = ft_itoa_base(nbr, base_dest);
	return (ptr);
}
