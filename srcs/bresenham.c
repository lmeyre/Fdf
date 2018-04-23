/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:03:44 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 02:14:42 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_bres_trace(t_env *env, int *curr_x, int *curr_y)
{
	if (env->path == 1)
	{
		(env->scale_x == 1) ? ++(*curr_x) : --(*curr_x);
		env->fault -= env->dy;
		if (env->fault < 0)
		{
			env->fault += env->dx;
			(env->scale_y == 1) ? ++(*curr_y) : --(*curr_y);
		}
	}
	else
	{
		(env->scale_y == 1) ? ++(*curr_y) : --(*curr_y);
		env->fault -= env->dx;
		if (env->fault < 0)
		{
			env->fault += env->dy;
			(env->scale_x == 1) ? ++(*curr_x) : --(*curr_x);
		}
	}
}

static void		bres_trace(t_env *env, int amount, int color_start)
{
	int		curr_x;
	int		curr_y;
	int		base_color;
	int		final_color;

	curr_x = env->pt1_x;
	curr_y = env->pt1_y;
	amount = fake_trace(env, env->fault, env->dx, env->dy);
	base_color = color_start;
	final_color = color_range(env->end_z);
	while (1)
	{
		if (env->color_option == 1 && amount != 0)
			manage_color(base_color, final_color, &color_start, amount);
		image_set_pixel(env, curr_x, curr_y, color_start);
		if (curr_x == env->pt2_x && curr_y == env->pt2_y)
			break ;
		fill_bres_trace(env, &curr_x, &curr_y);
		++env->color;
	}
}

static void		diff_bres_value(t_env *env)
{
	env->dx = ft_abs(env->pt1_x - env->pt2_x);
	env->dy = ft_abs(env->pt1_y - env->pt2_y);
	env->path = (env->dx < env->dy ? env->dy : env->dx);
	env->scale_x = (env->pt1_x < env->pt2_x ? 1 : -1);
	env->scale_y = (env->pt1_y < env->pt2_y ? 1 : -1);
	env->fault = env->path / 2;
	env->path = (env->dx < env->dy ? -1 : 1);
}

void			ft_bresenham(t_env *env)
{
	diff_bres_value(env);
	if (env->center != env->spacing)
	{
		perfect_center(env);
		env->center = env->spacing;
	}
	env->pt1_x += env->add_x;
	env->pt2_x += env->add_x;
	env->pt1_y += env->add_y;
	env->pt2_y += env->add_y;
	env->color = 0;
	bres_trace(env, 0, color_range(env->start_z));
}
