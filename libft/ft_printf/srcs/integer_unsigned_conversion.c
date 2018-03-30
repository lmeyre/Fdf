/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_unsigned_conversion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:15:15 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 21:15:17 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	long long	baseconv_modif(t_ptf *env,
		unsigned long long i, va_list *ap)
{
	if (env->frmt[env->index] == 'U' || env->frmt[env->index] == 'O')
		i = va_arg(*ap, unsigned long int);
	else if (env->hh_char == 1)
	{
		i = va_arg(*ap, int);
		i = (unsigned char)i;
	}
	else if (env->h_short == 1)
	{
		i = va_arg(*ap, int);
		i = (unsigned short int)i;
	}
	else if (env->l_long == 1)
		i = va_arg(*ap, unsigned long int);
	else if (env->ll_longlong == 1)
		i = va_arg(*ap, unsigned long long int);
	else if (env->j_intmax)
		i = va_arg(*ap, uintmax_t);
	else if (env->z_size == 1)
		i = va_arg(*ap, size_t);
	else
		i = va_arg(*ap, unsigned int);
	return (i);
}

static char			*filler(char c, unsigned long long i,
					t_ptf *env, char **bonus)
{
	char				*ptr;

	ptr = NULL;
	if (c == 'o' || c == 'O')
	{
		ptr = ft_itoa_base_unsigned(i, 8);
		if (env->dieze == 1 && ptr[0] != '0'
			&& env->precision <= ft_strlen(ptr))
			*bonus = ft_strdup("0");
	}
	else if (c == 'u' || c == 'U')
		ptr = ft_itoa_base_unsigned(i, 10);
	else if (c == 'x')
	{
		ptr = ft_itoa_base_unsigned(i, 16);
		if (env->dieze == 1 && ptr[0] != '0')
			*bonus = ft_strdup("0x");
	}
	else if (c == 'X')
	{
		ptr = ft_toupper_str(ft_itoa_base_unsigned(i, 16));
		if (env->dieze == 1 && ptr[0] != '0')
			*bonus = ft_strdup("0X");
	}
	return (ptr);
}

static	void		exception(char *ptr, int fake, t_ptf *env)
{
	if (fake == 0)
		printf_ft_putstr_buff(env, ptr);
	if (fake == 1 && (env->frmt[env->index] == 'o'
		|| env->frmt[env->index] == 'O') && env->dieze == 1)
		printf_ft_putchar_buff(env, '0');
}

static	void		write_base(t_ptf *env, char *ptr, char *bonus)
{
	int fake;
	int big;

	big = 0;
	fake = 0;
	big = (env->precision > ft_strlen(ptr) ? env->precision : ft_strlen(ptr));
	(bonus != NULL && (env->frmt[env->index] == 'x'
	|| env->frmt[env->index] == 'X')) ? big += 2 : 0;
	(bonus != NULL && (env->frmt[env->index] == 'o'
	|| env->frmt[env->index] == 'O')) ? big += 1 : 0;
	if (env->precision_on == 1 && env->precision <= 0 && !(ft_strcmp("0", ptr)))
	{
		fake = 1;
		--big;
	}
	if (env->zero == 0)
		env->neg == 0 ? printf_handle_width_other(env, big) : 0;
	printf_ft_putstr_buff(env, bonus);
	if (env->zero == 1)
		(env->neg == 0) ? printf_handle_width_other(env, big) : 0;
	printf_handle_precision_int(env, ft_strlen(ptr));
	exception(ptr, fake, env);
	(env->neg == 1) ? printf_handle_width_other(env, big) : 0;
	(env->size) += big;
}

void				printf_base_conv(t_ptf *env, va_list *ap, int big)
{
	unsigned long long	i;
	char				*ptr;
	char				*bonus;
	char				c;

	i = 0;
	(void)big;
	env->precision_on ? env->zero = 0 : 0;
	c = env->frmt[env->index];
	bonus = NULL;
	i = baseconv_modif(env, i, ap);
	ptr = filler(c, i, env, &bonus);
	write_base(env, ptr, bonus);
	if (env->precision_on == 1 && env->precision <= 0 && !(ft_strcmp("0", ptr))
		&& env->dieze == 1 && (env->frmt[env->index] == 'o'
		|| env->frmt[env->index] == 'O'))
		++(env->size);
	ft_strdel_two(&ptr, &bonus);
	++(env->index);
}
