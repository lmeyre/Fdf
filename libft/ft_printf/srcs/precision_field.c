/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:15:59 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 21:16:11 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printf_handle_width_other(t_ptf *env, int size)
{
	while (env->width > size)
	{
		if (env->zero)
			printf_ft_putchar_buff(env, '0');
		else
			printf_ft_putchar_buff(env, ' ');
		++size;
		++(env->size);
	}
}

void		printf_handle_precision_int(t_ptf *env, int size)
{
	while (env->precision > size)
	{
		++size;
		printf_ft_putchar_buff(env, '0');
	}
}

void		printf_handle_precision_str(t_ptf *env, char *str)
{
	int i;

	i = 0;
	while (env->precision > i && str[i])
		printf_ft_putchar_buff(env, str[i++]);
}

static	int	filler(wchar_t *wstr, int j)
{
	if (wstr[j] <= 0x7f)
		return (1);
	else if (wstr[j] <= 0x7ff)
		return (2);
	else if (wstr[j] <= 0xffff)
		return (3);
	else if (wstr[j] <= 0x1FFFFF)
		return (4);
	else
		return (-1);
}

void		printf_handle_precision_wstr(t_ptf *env, wchar_t *wstr)
{
	int i;
	int j;
	int tmp;

	j = 0;
	i = 0;
	while (env->precision >= i && wstr[j])
	{
		if ((tmp = filler(wstr, j)) == -1)
			return ;
		i += tmp;
		if (env->precision >= i)
		{
			env->size += tmp;
			printf_reset_buf(env);
			ft_putwchar(wstr[j]);
		}
		++j;
	}
}
