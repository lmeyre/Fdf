/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_effect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:31:48 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 23:32:03 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	join_point_percent_effect_right(t_env *env,
			int percent, int i, int j)
{
	int height;
	int tmp;

	height = env->multiply * env->spacing;
	if ((j + 1) < LST->lenght)
	{
		tmp = env->val_x - env->val_y + env->decale_x;
		env->pt1_x = env->val_x + (tmp * percent / 100) + env->decale_x;
		tmp = (env->val_y + env->val_x) / 2 + env->decale_y
		- (env->array[i][j] * height);
		env->pt1_y = env->val_y + (tmp * percent / 100) + env->decale_y
		- (env->array[i][j] * height) * percent / 100;
		tmp = env->val_x2 - env->val_y + env->decale_x;
		env->pt2_x = env->val_x2 + (tmp * percent / 100) + env->decale_x;
		tmp = (env->val_y + env->val_x2) / 2 + env->decale_y
		- (env->array[i][j + 1] * height);
		env->pt2_y = env->val_y + (tmp * percent / 100) + env->decale_y
		- (env->array[i][j + 1] * height) * percent / 100;
		env->start_z = (env->array[i][j]);
		env->end_z = (env->array[i][j + 1]);
		ft_bresenham(env);
	}
}

static void	join_point_percent_effect_bottom(t_env *env,
			int percent, int i, int j)
{
	int height;
	int tmp;

	height = env->multiply * env->spacing;
	if ((i + 1) < env->map_height && (env->lst->next
		&& (j < ((t_valist*)(env->lst->next->content))->lenght)))
	{
		tmp = env->val_x - env->val_y + env->decale_x;
		env->pt1_x = env->val_x + (tmp * percent / 100) + env->decale_x;
		tmp = (env->val_y + env->val_x) / 2 + env->decale_y
		- (env->array[i][j] * height);
		env->pt1_y = env->val_y + (tmp * percent / 100) + env->decale_y
		- (env->array[i][j] * height) * percent / 100;
		tmp = env->val_x - env->val_y2 + env->decale_x;
		env->pt2_x = env->val_x + (tmp * percent / 100) + env->decale_x;
		tmp = (env->val_y2 + env->val_x) / 2 + env->decale_y
		- (env->array[i + 1][j] * height);
		env->pt2_y = env->val_y2 + (tmp * percent / 100) + env->decale_y
		- (env->array[i + 1][j] * height) * percent / 100;
		env->start_z = (env->array[i][j]);
		env->end_z = (env->array[i + 1][j]);
		ft_bresenham(env);
	}
}

void		mlx_join_point_percent_effect(t_env *env,
			int percent, int i, int j)
{
	while (i < env->map_height)
	{
		while (j < LST->lenght)
		{
			env->val_x = j * env->spacing;
			env->val_y = i * env->spacing;
			env->val_x2 = (j + 1) * env->spacing;
			env->val_y2 = (i + 1) * env->spacing;
			join_point_percent_effect_right(env, percent, i, j);
			join_point_percent_effect_bottom(env, percent, i, j);
			++j;
		}
		if (env->lst->next)
			env->lst = env->lst->next;
		++i;
		j = 0;
	}
	while (env->lst->prev)
		env->lst = env->lst->prev;
}

int			animate_isometric_effect(t_env *env)
{
	join_100(env, Q);
	return (0);
}
