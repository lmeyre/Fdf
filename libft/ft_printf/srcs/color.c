/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:58:09 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/30 17:00:41 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	third_step(t_ptf *env, const char *format)
{
	if ((ft_strcmp_n("bgblue}", &format[env->index + 1], 7)) == 0)
	{
		ft_putstr("\x1b[44m");
		return (8);
	}
	else if ((ft_strcmp_n("bgmagenta}", &format[env->index + 1], 10)) == 0)
	{
		ft_putstr("\x1b[45m");
		return (11);
	}
	else if ((ft_strcmp_n("bgcyan}", &format[env->index + 1], 7)) == 0)
	{
		ft_putstr("\x1b[46m");
		return (8);
	}
	else if ((ft_strcmp_n("bgwhite}", &format[env->index + 1], 8)) == 0)
	{
		ft_putstr("\x1b[47m");
		return (9);
	}
	return (0);
}

static	int	second_step(t_ptf *env, const char *format)
{
	if ((ft_strcmp_n("bgblack}", &format[env->index + 1], 8)) == 0)
	{
		ft_putstr("\x1b[40m");
		return (9);
	}
	else if ((ft_strcmp_n("bgred}", &format[env->index + 1], 6)) == 0)
	{
		ft_putstr("\x1b[41m");
		return (7);
	}
	else if ((ft_strcmp_n("bggreen}", &format[env->index + 1], 8)) == 0)
	{
		ft_putstr("\x1b[42m");
		return (9);
	}
	else if ((ft_strcmp_n("bgyellow}", &format[env->index + 1], 9)) == 0)
	{
		ft_putstr("\x1b[43m");
		return (10);
	}
	return (third_step(env, format));
}

static	int	first_step(t_ptf *env, const char *format)
{
	if ((ft_strcmp_n("blue}", &format[env->index + 1], 5)) == 0)
	{
		ft_putstr("\x1B[34m");
		return (6);
	}
	else if ((ft_strcmp_n("magenta}", &format[env->index + 1], 8)) == 0)
	{
		ft_putstr("\x1B[35m");
		return (9);
	}
	else if ((ft_strcmp_n("cyan}", &format[env->index + 1], 5)) == 0)
	{
		ft_putstr("\x1B[36m");
		return (6);
	}
	else if ((ft_strcmp_n("white}", &format[env->index + 1], 6)) == 0)
	{
		ft_putstr("\x1B[37m");
		return (7);
	}
	return (second_step(env, format));
}

static	int	basic_step(t_ptf *env, const char *format)
{
	(ft_strcmp_n("black}", &format[env->index + 1], 6) == 0) ?
		ft_putstr("\x1B[30m") : 0;
	if ((ft_strcmp_n("black}", &format[env->index + 1], 6)) == 0)
		return (7);
	else if ((ft_strcmp_n("red}", &format[env->index + 1], 4)) == 0)
	{
		ft_putstr("\x1B[31m");
		return (5);
	}
	else if ((ft_strcmp_n("green}", &format[env->index + 1], 6)) == 0)
	{
		ft_putstr("\x1B[32m");
		return (7);
	}
	else if ((ft_strcmp_n("yellow}", &format[env->index + 1], 7)) == 0)
	{
		ft_putstr("\x1B[33m");
		return (8);
	}
	else if ((ft_strcmp_n("eoc}", &format[env->index + 1], 4)) == 0)
	{
		ft_putstr("\x1b[40m\x1B[37m");
		return (5);
	}
	return (first_step(env, format));
}

void		printf_check_color(t_ptf *env, const char *format)
{
	int verif;

	printf_reset_buf(env);
	verif = basic_step(env, format);
	env->index += verif;
	verif == 0 ? ++(env->size) : 0;
	verif == 0 ? printf_ft_putchar_buff(env, format[env->index++]) : 0;
}
