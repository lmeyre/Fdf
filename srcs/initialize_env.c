/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:17:54 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 01:35:29 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	help_initialize(t_env *env)
{
	env->dx = 0;
	env->dy = 0;
	env->decale_x = 0;
	env->decale_y = 0;
	env->spacing = 10;
	env->multiply = 1;
	env->scale_x = 0;
	env->scale_y = 0;
	env->fault = 0;
	env->path = 0;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->tmp = 0;
	env->center = 42;
	env->start_z = 0;
	env->end_z = 0;
	env->bpp = 0;
	env->s_l = 0;
	env->endian = 0;
	env->val_x = 0;
	env->val_y = 0;
	env->val_x2 = 0;
	env->val_y2 = 0;
}

t_env		*initialize_env(void)
{
	t_env *env;

	env = (t_env*)malloc(sizeof(t_env));
	ft_bzero(env, sizeof(t_env));
	env->array = NULL;
	env->origin_array = NULL;
	env->lst = NULL;
	env->map_width = 0;
	env->map_height = 0;
	env->win_height = 0;
	env->win_width = 0;
	env->pt1_x = 0;
	env->pt2_x = 0;
	env->pt1_y = 0;
	env->pt2_y = 0;
	env->add_x = 0;
	env->add_y = 0;
	env->anim_val = 100;
	env->color_option = -1;
	env->origin_spacing = 10;
	help_initialize(env);
	return (env);
}

void		manage_color(int base_color,
				int final_color, int *color, int amount)
{
	int	difference;

	if (base_color == final_color)
		return ;
	difference = ft_abs(base_color - final_color);
	if (amount == 0)
		ft_printf("CA VA CRSH\n\n");
	if (base_color > final_color)
	{
		*color -= difference / amount;
	}
	else if (base_color < final_color)
	{
		*color += difference / amount;
	}
}

static void	fill_moove(int key, t_env *env)
{
	if (key == PAD_THREE)
	{
		env->decale_y += MOOVE_INTENSITY;
		env->decale_x += MOOVE_INTENSITY;
	}
	else if (key == PAD_SEVEN)
	{
		env->decale_y -= MOOVE_INTENSITY;
		env->decale_x -= MOOVE_INTENSITY;
	}
	else if (key == PAD_NINE)
	{
		env->decale_y -= MOOVE_INTENSITY;
		env->decale_x += MOOVE_INTENSITY;
	}
}

void		key_moove(int key, t_env *env)
{
	if (key == PAD_TWO)
		env->decale_y += MOOVE_INTENSITY;
	else if (key == PAD_EIGHT)
		env->decale_y -= MOOVE_INTENSITY;
	else if (key == PAD_SIX)
		env->decale_x += MOOVE_INTENSITY;
	else if (key == PAD_FOUR)
		env->decale_x -= MOOVE_INTENSITY;
	else if (key == PAD_ONE)
	{
		env->decale_y += MOOVE_INTENSITY;
		env->decale_x -= MOOVE_INTENSITY;
	}
	else
		fill_moove(key, env);
}
