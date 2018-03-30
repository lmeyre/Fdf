/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:54:08 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 23:54:42 by lmeyre           ###   ########.fr       */
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

char			*ft_itoa_base_unsigned(unsigned long long n, int base)
{
	int			j;
	char		*ptr;
	char		converter[17];

	ft_strcpy(converter, "0123456789abcdef");
	if (base == 0)
		return (NULL);
	if ((ptr = exception(n)) != NULL)
		return (ptr);
	j = ft_filler(n, 0, base);
	if (!(ptr = ft_strnew(j)))
		return (NULL);
	j--;
	while (n >= 1)
	{
		ptr[j--] = converter[(n % base)];
		n /= base;
	}
	return (ptr);
}
