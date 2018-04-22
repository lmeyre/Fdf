/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:41:24 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/30 16:41:57 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int			fdf(t_env *env)
{
	env->mlx_ptr = mlx_init();
	//ft_printf("widht = %d et height = %d\n", env->map_width, env->map_height);
	mlx_window_size(env);
	env->img =  mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->s_l), &(env->endian));
//	ft_printf("la char * = \n|%s|\nbpp = %d ls = %det endian = %d\nwin width = %d et win height=%d\n", env->img, env->bpp, env->s_l, env->endian, env->win_width, env->win_height);
	//ft_printf("decale x = %d et y = %d, win width = %d et win height = %d, map width = %d et map height = %d, valeur soustraite = %d, et total = %d\n", env->decale_x, env->decale_y,env->win_width, env->win_height, env->map_width, env->map_height, env->map_width * env->spacing / 2, (env->win_width / 2) - (env->map_width * env->spacing / 2));
	//mlx_map_point(env);
//	mlx_join_point_above(env);
	new_image(env);
	//animate_isometric(env);
	mlx_pixel_put(env->mlx_ptr, env->win_ptr, 10, env->win_height / 2, 0xFFFFFF); // enlever ca
	mlx_key_hook(env->win_ptr, fdf_key, env);
	//mlx_loop_hook(env->mlx_ptr, animate_isometric, env);

	mlx_loop(env->mlx_ptr);
	return (1);
}

void	mlx_window_size(t_env *env)
{
	int valx;
    int valy;
    int end_x;
    int end_y;

	env->win_width = env->map_width * 10 + 500;
	env->win_height = env->map_height * 10 + 500;
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
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->win_width, env->win_height, "fdf");// a proteger ?
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_width, env->win_height);
}

void            reset_image(t_env *env)
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
