/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:38:21 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 01:43:01 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		right_link(t_env *env, int j, int i, int height)
{
	int val_x;
	int val_y;

	val_x = env->bres_x;
	val_y = env->bres_y;
	if ((j + 1) < LST->lenght)
	{
		env->pt1_x = val_x - val_y + env->decale_x;
		env->pt1_y = (val_y + val_x) / 2 + env->decale_y
		- (env->array[i][j] * height);
		env->pt2_x = ((j + 1) * env->spacing) - val_y + env->decale_x;
		env->pt2_y = (val_y + (j + 1) * env->spacing) / 2 + env->decale_y
		- (env->array[i][j + 1] * height);
		env->start_z = (env->array[i][j]);
		env->end_z = (env->array[i][j + 1]);
		ft_bresenham(env);
	}
}

static void		bottom_link(t_env *env, int j, int i, int height)
{
	int val_x;
	int val_y;

	val_x = env->bres_x;
	val_y = env->bres_y;
	if ((i + 1) < env->map_height && (env->lst->next
	&& (j < ((t_valist*)(env->lst->next->content))->lenght)))
	{
		env->pt1_x = val_x - val_y + env->decale_x;
		env->pt1_y = (val_y + val_x) / 2 + env->decale_y
		- (env->array[i][j] * height);
		env->pt2_x = val_x - ((i + 1) * env->spacing) + env->decale_x;
		env->pt2_y = ((i + 1) * env->spacing + val_x) / 2 + env->decale_y
		- (env->array[i + 1][j] * height);
		env->start_z = (env->array[i][j]);
		env->end_z = (env->array[i + 1][j]);
		ft_bresenham(env);
	}
}

void			mlx_join_point(t_env *env)
{
	int i;
	int j;
	int height;

	(env->spacing <= 0) ? env->spacing = 1 : 0;
	height = env->multiply * env->spacing;
	i = 0;
	j = 0;
	while (i < env->map_height)
	{
		while (j < LST->lenght)
		{
			env->bres_x = j * env->spacing;
			env->bres_y = i * env->spacing;
			right_link(env, j, i, height);
			bottom_link(env, j, i, height);
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
