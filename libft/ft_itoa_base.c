/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:06:12 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 23:53:47 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*exception(long long n)
{
	char	*ptr;

	if (n == 0)
	{
		if (!(ptr = ft_strnew(1)))
			return (NULL);
		ptr = ft_strcpy(ptr, "0");
		return (ptr);
	}
	return (NULL);
}

static int		ft_filler(unsigned long long i, int j, int base)
{
	while (i >= 1)
	{
		i /= base;
		j++;
	}
	return (j);
}

char			*ft_itoa_base(long long n, int base)
{
	int					j;
	char				*ptr;
	int					neg;
	char				converter[17];
	unsigned long long	reverse;

	ft_strcpy(converter, "0123456789abcdef");
	if (base == 0)
		return (NULL);
	if ((ptr = exception(n)) != NULL)
		return (ptr);
	neg = n < 0 ? -1 : 0;
	reverse = (neg == -1 ? n * -1 : n);
	j = ft_filler(reverse, 0, base);
	neg == -1 ? j++ : j;
	if (!(ptr = ft_strnew(j)))
		return (NULL);
	j--;
	while (reverse >= 1)
	{
		ptr[j--] = converter[(reverse % base)];
		reverse /= base;
	}
	neg == -1 ? ptr[j] = '-' : neg;
	return (ptr);
}
