/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:27:58 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 01:31:39 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		key_zoom(int key, t_env *env)
{
	if (key == MORE)
		env->spacing += 3;
	else if (key == LESS)
		env->spacing -= 3;
}

static void		key_height_multiplier(int key, t_env *env)
{
	if (key == O)
		env->multiply += 1;
	else if (key == L)
		env->multiply -= 1;
}

static void		key_height(int key, t_env *env)
{
	if (key == UP_ARROW)
		help_value(1, env);
	else if (key == DOWN_ARROW)
		help_value(-1, env);
}

static void		fill_fdf_key(int key, t_env *env)
{
	if (key == T)
	{
		env->anim_val = 100;
		mlx_loop_hook(env->mlx_ptr, animate_isometric_effect, env);
	}
	else if (key == SPACEBAR)
		reset_image(env);
	else if (key == C)
		env->color_option *= -1;
}

int				fdf_key(int key, t_env *env)
{
	if (key == MORE || key == LESS)
		key_zoom(key, env);
	else if (key == PAD_ONE || key == PAD_TWO || key == PAD_THREE
	|| key == PAD_FOUR || key == PAD_SIX || key == PAD_SEVEN
	|| key == PAD_EIGHT || key == PAD_NINE)
		key_moove(key, env);
	else if (key == O || key == L)
		key_height_multiplier(key, env);
	else if (key == UP_ARROW || key == DOWN_ARROW)
		key_height(key, env);
	else if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key == Q)
	{
		env->anim_val = 100;
		mlx_loop_hook(env->mlx_ptr, animate_isometric, env);
	}
	else
		fill_fdf_key(key, env);
	new_image(env);
	return (0);
}
