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

#include "fdf.h"


/*
void mlx_map_point(t_env *env)
{
	int i;
	int j;
	int	val_x;
	int	val_y;
	int height;

	if (env->spacing <= 0)
		env->spacing = 1;
	height = env->multiply * env->spacing;
	i = 0;
	j = 0;
	while(i < env->map_height) // I = =Y
	{
		//ft_printf("lst lenght = %d\n", LST->lenght);
		while (j < LST->lenght) // J = X
		{
			
		//	else if (env->spacing == 6) // gerer en fonction de la variable d augmention key zoom
				//env->spacing = 5;
			
			val_x = j * env->spacing;
			val_y = i * env->spacing;
			ft_printf("val x=  %d, val y = %d, et decale  x = %d\n", val_x, val_y, env->decale_x);
				mlx_pixel_put(env->mlx_ptr, env->win_ptr, val_x - val_y + env->decale_x, (val_y + val_x) / 2 - (env->array[i][j] * height) + env->decale_y, 0xFFFFFF); // le * 10 et + 100 sont a voir precisement, car arbitraires ||  le *2 aussi
			++j;	
			//printf("on a mit x a %d et y a %d\n", val_x - val_y + env->decale_x, (val_y + val_x) / 2 + env->decale_y - (env->array[i][j] * env->multiply));									  // X - Y                   (Y + X) / 2
			//return ;
		}
		if (env->lst->next)
			env->lst = env->lst->next;
		++i;
		j = 0;
	}
	while (env->lst->prev)
		env->lst = env->lst->prev;
}*/
/*
void	mlx_join_point_above(t_env *env) // on va faire , on parcourst tout les point et pour chqaue point on fait un lien avec celui qui est en bas + a droite
{
	int i;
	int j;
	int val_x;
	int val_y;
	int height;

	if (env->spacing <= 0)
		env->spacing = 1;
	height = env->multiply * env->spacing;
	i = 0;
	j = 0;
	while (i < env->map_height) // i = y
	{
		while (j < LST->lenght) // j=  x
		{
			val_x = j * env->spacing;
			val_y = i * env->spacing;
			
			if ((j + 1) < LST->lenght)
			{
				env->pt1_x = val_x + env->decale_x;
				env->pt1_y = val_y  + env->decale_y;
				env->pt2_x = ((j + 1) * env->spacing) + env->decale_x;
				env->pt2_y = val_y + env->decale_y ;
				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i][j + 1]);
				ft_bresenham(env);
			}
			if ((i + 1) < env->map_height && (env->lst->next && (j < ((t_valist*)(env->lst->next->content))->lenght))) // bien verifier celle la particluierement
			{
				env->pt1_x = val_x + env->decale_x;
				env->pt1_y = val_y + env->decale_y;
				env->pt2_x = val_x + env->decale_x;
				env->pt2_y = ((i + 1) * env->spacing) + env->decale_y;
				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i + 1][j]);
				ft_bresenham(env);
			}
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
*/
void	mlx_join_point(t_env *env) // on va faire , on parcourst tout les point et pour chqaue point on fait un lien avec celui qui est en bas + a droite
{
	int i;
	int j;
	int val_x;
	int val_y;
	int height;


	env->tmp = ft_abs(env->map_max) - ft_abs(env->map_min);// remoove
	if (env->spacing <= 0)
		env->spacing = 1;
	height = env->multiply * env->spacing;
	i = 0;
	j = 0;
	while (i < env->map_height) // i = y
	{
		while (j < LST->lenght) // j=  x
		{
			val_x = j * env->spacing;
			val_y = i * env->spacing;
			
			if ((j + 1) < LST->lenght)
			{
				
				env->pt1_x = val_x - val_y + env->decale_x;
				env->pt1_y = (val_y + val_x) / 2 + env->decale_y  - (env->array[i][j] * height); // !!!
				env->pt2_x = ((j + 1) * env->spacing)  - val_y + env->decale_x;
				env->pt2_y = (val_y + (j + 1) * env->spacing) / 2 + env->decale_y - (env->array[i][j + 1] * height);
				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i][j + 1]);
				ft_bresenham(env);
			}
			if ((i + 1) < env->map_height && (env->lst->next && (j < ((t_valist*)(env->lst->next->content))->lenght))) // bien verifier celle la particluierement
			{
				env->pt1_x = val_x - val_y + env->decale_x;
				env->pt1_y = (val_y + val_x) / 2 + env->decale_y - (env->array[i][j] * height);
				env->pt2_x = val_x - ((i + 1) * env->spacing) + env->decale_x;
				env->pt2_y = ((i + 1) * env->spacing + val_x) / 2 + env->decale_y - (env->array[i + 1][j] * height);
				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i + 1][j]);
				ft_bresenham(env);
			}
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
