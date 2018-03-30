/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:19:07 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 21:24:07 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printf_flag_start(t_ptf *env)
{
	if (env->frmt[env->index] == 'l' || env->frmt[env->index] == 'h'
			|| env->frmt[env->index] == 'j' || env->frmt[env->index] == 'z')
	{
		if (env->frmt[env->index] == 'h' && env->frmt[env->index + 1] == 'h')
		{
			env->hh_char = 1;
			++(env->index);
		}
		else if (env->frmt[env->index] == 'h')
			env->h_short = 1;
		else if (env->frmt[env->index] == 'l'
				&& env->frmt[env->index + 1] == 'l')
		{
			env->ll_longlong = 1;
			++(env->index);
		}
		else if (env->frmt[env->index] == 'l')
			env->l_long = 1;
		else if (env->frmt[env->index] == 'j')
			env->j_intmax = 1;
		else if (env->frmt[env->index] == 'z')
			env->z_size = 1;
		++(env->index);
	}
}

void		printf_precision_start(t_ptf *env)
{
	int x;

	x = 0;
	if (env->frmt[env->index] == '.')
	{
		env->precision_on = 1;
		++(env->index);
	}
	if (env->frmt[(env->index) - 1] == '.' && ((env->frmt[env->index] >= '0'
		&& env->frmt[env->index] <= '9') || env->frmt[env->index] == '-'))
	{
		if (env->frmt[env->index] == '-')
			++x;
		while (env->frmt[(env->index) + x] >= '0'
				&& env->frmt[(env->index) + x] <= '9')
			++x;
		env->precision = ft_atoi(&env->frmt[env->index]);
		if (env->precision <= 0)
			env->precision = 0;
		env->index += x;
	}
}

void		printf_field_width_start(t_ptf *env)
{
	int x;

	x = 0;
	if (env->frmt[env->index] >= '1' && env->frmt[env->index] <= '9')
	{
		while (env->frmt[(env->index) + x] >= '0'
				&& env->frmt[(env->index) + x] <= '9')
			++x;
		env->width = ft_atoi(&env->frmt[env->index]);
		env->index += x;
	}
}

void		printf_attrib_start(t_ptf *env)
{
	while (env->frmt[env->index] == '#'
			|| env->frmt[env->index] == '0' || env->frmt[env->index] == '-'
			|| env->frmt[env->index] == ' ' || env->frmt[env->index] == '+')
	{
		(env->frmt[env->index] == '#') ? env->dieze = 1 : 0;
		(env->frmt[env->index] == '0') ? env->zero = 1 : 0;
		(env->frmt[env->index] == '-') ? env->neg = 1 : 0;
		(env->frmt[env->index] == ' ') ? env->space = 1 : 0;
		(env->frmt[env->index] == '+') ? env->pos = 1 : 0;
		++(env->index);
	}
	if (env->space && env->pos)
		env->space = 0;
	if (env->zero && env->neg)
		env->zero = 0;
}

int			printf_convertion_start(t_ptf *env, va_list *ap)
{
	char	tab_conv[17];
	int		x;
	void	(*trigger[16])(t_ptf*, va_list*, int);

	printf_init_conv_tab(trigger);
	x = -1;
	ft_strcpy(tab_conv, "dsioxXcSCpuDOU%b");
	while (tab_conv[++x])
	{
		if (tab_conv[x] == env->frmt[env->index])
		{
			tab_conv[x] == 'D' ? env->l_long = 1 : 0;
			tab_conv[x] == 'U' ? env->l_long = 1 : 0;
			tab_conv[x] == 'O' ? env->l_long = 1 : 0;
			trigger[x](env, ap, 0);
			return (1);
		}
	}
	printf_handle_width_other(env, 1);
	return (1);
}
