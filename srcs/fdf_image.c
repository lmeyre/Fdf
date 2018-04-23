/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:43:55 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 02:44:41 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			image_set_pixel(t_env *env, int x, int y, int color)
{
	if (x < 0 || x >= env->win_width || y < 0 || y >= env->win_height)
		return ;
	*((int*)(env->img + ((x + y * env->win_width) * 4))) = color;
}

void			new_image(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	if (env->img)
		ft_bzero(env->img, env->win_width * env->win_height * 4);
	mlx_join_point(env);
	mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);
	man_fdf(env);
}
