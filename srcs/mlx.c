/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:38:21 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/30 20:42:39 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	mlx_window_size(t_env *env)
{
	if (env->map_width <= 10) // melange normal car les colonne du tableau sont en largeurs
		env->win_width = env->map_width * 100;
	else if (env->map_width <= 20)
		env->win_width = env->map_width * 70;
	else if (env->map_width <= 50)
		env->win_width = env->map_width * 40;
	else if (env->map_width <= 100)
		env->win_width = env->map_width * 20;
	else
		env->win_width = env->map_width * 10;

	if (env->map_height <= 10)
		env->win_height = env->map_height * 100;
	else if (env->map_height <= 20)
		env->win_height = env->map_height * 70;
	else if (env->map_height <= 50)
		env->win_height = env->map_height * 40;
	else if (env->map_height <= 100)
		env->win_height = env->map_height * 20;
	else
		env->win_height = env->map_height * 10;

	env->win_ptr = mlx_new_window(env->mlx_ptr, env->win_width, env->win_height, "fdf");// a proteger ?
}

static void mlx_map_point(t_env *env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < env->map_width)
	{
		while (j < env->map_height)
		{
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, i * 100 + 10, j * 100 + 10, 0xFFFFFF); // premier param est la largeur et le deuxieme la hauteur
			++j;
		}
		++i;
		j = 0;
	}
}

int			mlx_fdf(t_env *env)
{
	env->mlx_ptr = mlx_init();
	ft_printf("widht = %d et height = %d\n", env->map_width, env->map_height);
	mlx_window_size(env);
	mlx_map_point(env);
	//env->win_ptr = mlx_new_window(env->mlx_ptr, 800, 800, "try");
	//mlx_pixel_put(env->mlx_ptr, env->win_ptr, 600, 400, 0xFFFFFFF);
	//mlx_key_hook(env->win_ptr, test, (void*)0);
	mlx_loop(env->mlx_ptr);

	return (1);
}
