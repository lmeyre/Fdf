/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:38:36 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 02:42:44 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		assign_value(t_env *env, int width, int link)
{
	t_list *tmplst;

	if (!(tmplst = ft_lst_new(sizeof(t_valist*))))
		exit(EXIT_SUCCESS);
	((t_valist*)(tmplst->content))->link = link;
	((t_valist*)(tmplst->content))->lenght = width;
	ft_lst_add_end(&env->lst, tmplst);
}

void		help_value(int value, t_env *env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < env->map_height)
	{
		while (j < LST->lenght)
		{
			if (env->origin_array[i][j] != 0)
				env->array[i][j] += value;
			++j;
		}
		++i;
		j = 0;
	}
}

void		man_fdf(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, 0xFFFFFF,
			"PAD to move -> 1/2/3/4/6/7/8/9");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 30, 0xFFFFFF,
			"Arrow keys to change height -> Up & Down");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 50, 0xFFFFFF,
			"Zoom -> + & -");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70, 0xFFFFFF,
			"Exponential height -> O & L");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 110, 0xFFFFFF,
			"Animation/Effect -> Q/T");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 130, 0xFFFFFF,
			"Graduate Colors -> C");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 90, 0xFFFFFF,
			"Reset -> Space");
}

int			color_range(int height)
{
	static int tab_color[12] = {0x0000FF, 0x0077FF, 0x00FFFF, 0x00FF77,
		0x00FF00, 0x77FF00, 0xFFFF00, 0xFF7700,
		0xFF0000, 0xFF0077, 0xFF00FF, 0x7700FF};

	if (height == 0)
		return (0xFFFFFF);
	if (height > 0)
		while (height > 11)
			height -= 12;
	else
		while (height < 0)
			height += 12;
	return (tab_color[height]);
}

void		perfect_center(t_env *env)
{
	int tmpx;
	int tmpy;
	int end_x;
	int end_y;

	end_x = ((env->map_width - 1) * env->spacing)
	- ((env->map_height - 1) * env->spacing);
	end_y = (((env->map_width - 1) * env->spacing)
	+ ((env->map_height - 1) * env->spacing)) / 2;
	tmpx = (env->map_width * 10 + 500);
	tmpy = (env->map_height * 10 + 500);
	tmpx > 2550 ? tmpx = 2550 : 0;
	tmpy > 1400 ? tmpy = 1400 : 0;
	env->add_x = tmpx / 2 - end_x / 2;
	env->add_y = tmpy / 2 - end_y / 2;
}
