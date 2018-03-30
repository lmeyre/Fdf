/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:59:41 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/28 22:32:28 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printf_handle_space(int *count, int neg, t_ptf *env)
{
	if (neg == 0 && env->space == 1)
	{
		printf_ft_putchar_buff(env, ' ');
		++(*count);
	}
}

void		printf_handle_pos(t_ptf *env, int number)
{
	if (env->pos == 1 && number >= 0)
		printf_ft_putchar_buff(env, '+');
}
