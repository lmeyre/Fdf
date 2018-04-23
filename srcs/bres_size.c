/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:41:26 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 02:41:52 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fake_trace_one(t_env *env, int fault, int dx, int dy)
{
	int count;
	int curr_x;
	int curr_y;

	count = 0;
	curr_x = env->pt1_x;
	curr_y = env->pt1_y;
	while (1)
	{
		if (curr_x == env->pt2_x && curr_y == env->pt2_y)
			return (count);
		(env->scale_x == 1) ? ++curr_x : --curr_x;
		fault -= dy;
		if (fault < 0)
		{
			fault += dx;
			(env->scale_y == 1) ? ++curr_y : --curr_y;
		}
		++count;
	}
}

static int		fake_trace_other(t_env *env, int fault, int dx, int dy)
{
	int count;
	int curr_x;
	int curr_y;

	count = 0;
	curr_x = env->pt1_x;
	curr_y = env->pt1_y;
	while (1)
	{
		if (curr_x == env->pt2_x && curr_y == env->pt2_y)
			return (count);
		(env->scale_y == 1) ? ++curr_y : --curr_y;
		fault -= dx;
		if (fault < 0)
		{
			fault += dy;
			(env->scale_x == 1) ? ++curr_x : --curr_x;
		}
		++count;
	}
}

int				fake_trace(t_env *env, int fault, int dx, int dy)
{
	if (env->path == 1)
		return (fake_trace_one(env, fault, dx, dy));
	else
		return (fake_trace_other(env, fault, dx, dy));
}
