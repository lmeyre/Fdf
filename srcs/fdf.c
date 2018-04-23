/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:41:24 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 01:20:10 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf(t_env *env)
{
	env->mlx_ptr = mlx_init();
	env->win_width = env->map_width * 10 + 500;
	env->win_height = env->map_height * 10 + 500;
	mlx_window_size(env, 0, 0);
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_width, env->win_height);
	env->img = mlx_get_data_addr(env->img_ptr,
			&(env->bpp), &(env->s_l), &(env->endian));
	new_image(env);
	mlx_key_hook(env->win_ptr, fdf_key, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}

void		mlx_window_size(t_env *env, int valx, int valy)
{
	int end_x;
	int end_y;

	valx = ((env->map_width - 1) * env->spacing);
	valy = ((env->map_height - 1) * env->spacing);
	end_x = valx - valy;
	end_y = (valx + valy) / 2;
	while (end_x * 2 > env->win_width)
	{
		--env->spacing;
		valx = ((env->map_width - 1) * env->spacing);
		valy = ((env->map_height - 1) * env->spacing);
		end_x = valx - valy;
		end_y = (valx + valy) / 2;
	}
	while (end_y * 2 > env->win_height)
	{
		--env->spacing;
		valx = ((env->map_width - 1) * env->spacing);
		valy = ((env->map_height - 1) * env->spacing);
		end_x = valx - valy;
		end_y = (valx + valy) / 2;
	}
	env->win_ptr = mlx_new_window(env->mlx_ptr,
				env->win_width, env->win_height, "fdf");
}

void		reset_image(t_env *env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < env->map_height)
	{
		while (j < LST->lenght)
		{
			env->array[i][j] = env->origin_array[i][j];
			++j;
		}
		if (env->lst->next)
			env->lst = env->lst->next;
		++i;
		j = 0;
	}
	env->center = 42;
	env->decale_x = 0;
	env->decale_y = 0;
	env->spacing = 10;
	env->multiply = 1;
	while (env->lst->prev)
		env->lst = env->lst->prev;
}
