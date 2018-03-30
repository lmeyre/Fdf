/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:48:23 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 19:49:11 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_ptf		*printf_initialize_env(void)
{
	t_ptf *env;

	if (!(env = (t_ptf*)malloc(sizeof(t_ptf))))
		return (NULL);
	env->frmt = NULL;
	env->size = 0;
	env->index = 0;
	env->index_buff = 0;
	env->dieze = 0;
	env->zero = 0;
	env->neg = 0;
	env->space = 0;
	env->pos = 0;
	env->width = 0;
	env->hh_char = 0;
	env->h_short = 0;
	env->l_long = 0;
	env->ll_longlong = 0;
	env->j_intmax = 0;
	env->z_size = 0;
	env->precision = 0;
	env->precision_on = 0;
	return (env);
}

void		printf_reset_value(t_ptf *env)
{
	env->dieze = 0;
	env->zero = 0;
	env->neg = 0;
	env->space = 0;
	env->pos = 0;
	env->width = 0;
	env->hh_char = 0;
	env->h_short = 0;
	env->l_long = 0;
	env->ll_longlong = 0;
	env->j_intmax = 0;
	env->z_size = 0;
	env->precision = 0;
	env->precision_on = 0;
}

void		printf_init_conv_tab(void (*trigger[])(t_ptf*, va_list*, int))
{
	trigger[0] = &printf_d_conv;
	trigger[1] = &printf_s_conv;
	trigger[2] = &printf_d_conv;
	trigger[3] = &printf_base_conv;
	trigger[4] = &printf_base_conv;
	trigger[5] = &printf_base_conv;
	trigger[6] = &printf_c_conv;
	trigger[7] = &printf_as_conv;
	trigger[8] = &printf_ac_conv;
	trigger[9] = &printf_p_conv;
	trigger[10] = &printf_base_conv;
	trigger[11] = &printf_d_conv;
	trigger[12] = &printf_base_conv;
	trigger[13] = &printf_base_conv;
	trigger[14] = &printf_percent_conv;
	trigger[15] = &printf_b_conv;
}
