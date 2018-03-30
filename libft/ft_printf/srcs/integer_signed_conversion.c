/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interger_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:49:30 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/28 22:04:10 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int			filler(t_ptf *env, long long x, int *bigger)
{
	int fake;

	fake = 0;
	if (env->precision_on == 1 && env->precision <= 0 & x == 0)
	{
		fake = 1;
		--(*bigger);
		--(env->size);
	}
	return (fake);
}

static	void		write_conv(t_ptf *env, long long x, int bigger, char *str)
{
	int		size;
	int		fake;

	fake = filler(env, x, &bigger);
	if (env->zero == 0)
		env->neg == 0 ? printf_handle_width_other(env, bigger) : 0;
	size = ft_int_length(x);
	x < 0 ? printf_ft_putchar_buff(env, '-') : 0;
	printf_handle_pos(env, x);
	if (env->zero == 1)
		env->neg == 0 ? printf_handle_width_other(env, bigger) : 0;
	printf_handle_precision_int(env, size);
	if (fake == 0)
	{
		env->frmt[env->index - 1] == 'b' ? str = ft_itoa_base(x, 2) : 0;
		env->frmt[env->index - 1] != 'b' ? str = ft_itoa_base(x, 10) : 0;
		if (!str)
			return ;
		else if (str[0] == '-')
			printf_ft_putstr_buff(env, str + 1);
		else
			printf_ft_putstr_buff(env, str);
		ft_strdel(&str);
	}
	env->neg == 1 ? printf_handle_width_other(env, bigger) : 0;
}

static	long long	dconv_modif(t_ptf *env, long long x, va_list *ap)
{
	if (env->frmt[env->index - 1] == 'D')
		x = va_arg(*ap, signed long int);
	else if (env->hh_char == 1)
	{
		x = va_arg(*ap, int);
		x = (signed char)x;
	}
	else if (env->h_short == 1)
	{
		x = va_arg(*ap, int);
		x = (signed short int)x;
	}
	else if (env->l_long == 1)
		x = va_arg(*ap, signed long int);
	else if (env->ll_longlong == 1)
		x = va_arg(*ap, signed long long int);
	else if (env->j_intmax)
		x = va_arg(*ap, intmax_t);
	else if (env->z_size == 1)
		x = va_arg(*ap, size_t);
	else
		x = va_arg(*ap, int);
	return (x);
}

void				printf_d_conv(t_ptf *env, va_list *ap, int count)
{
	long long	x;
	int			bigger;
	int			neg;
	char		*str;

	str = NULL;
	++(env->index);
	x = 0;
	neg = 0;
	env->precision_on ? env->zero = 0 : 0;
	x = dconv_modif(env, x, ap);
	neg = (x < 0) ? 1 : 0;
	if (env->pos == 1 && x >= 0)
		++count;
	printf_handle_space(&count, neg, env);
	x < 0 ? ++count : 0;
	bigger = count + (env->precision > ft_int_length(x) ?
						env->precision : ft_int_length(x));
	write_conv(env, x, bigger, str);
	env->size += bigger;
}

void				printf_b_conv(t_ptf *env, va_list *ap, int count)
{
	long long	x;
	int			bigger;
	int			neg;
	char		*str;

	str = NULL;
	++(env->index);
	x = 0;
	neg = 0;
	x = dconv_modif(env, x, ap);
	neg = (x < 0) ? 1 : 0;
	if (env->pos == 1 && x >= 0)
		++count;
	printf_handle_space(&count, neg, env);
	x < 0 ? ++count : 0;
	bigger = count + (env->precision > ft_int_length(x) ?
						env->precision : ft_int_length(x));
	write_conv(env, x, bigger, str);
	env->size += bigger;
}
