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

static void	mlx_window_size(t_env *env)
{
	if (env->map_width <= 10) // melange normal car les colonne du tableau sont en largeurs , on a regler le soucis 
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

	env->win_ptr = mlx_new_window(env->mlx_ptr, env->win_width/*500*/, env->win_height/*500*/, "fdf");// a proteger ?
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_width, env->win_height);
}

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
}

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

int			mlx_fdf(t_env *env)
{
	env->mlx_ptr = mlx_init();
	//ft_printf("widht = %d et height = %d\n", env->map_width, env->map_height);
	mlx_window_size(env);
	env->img =  mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->s_l), &(env->endian));
//	ft_printf("la char * = \n|%s|\nbpp = %d ls = %det endian = %d\nwin width = %d et win height=%d\n", env->img, env->bpp, env->s_l, env->endian, env->win_width, env->win_height);
	//ft_printf("decale x = %d et y = %d, win width = %d et win height = %d, map width = %d et map height = %d, valeur soustraite = %d, et total = %d\n", env->decale_x, env->decale_y,env->win_width, env->win_height, env->map_width, env->map_height, env->map_width * env->spacing / 2, (env->win_width / 2) - (env->map_width * env->spacing / 2));
	//mlx_map_point(env);
//	mlx_join_point(env);
	new_image(env);
	//animate_isometric(env);
	mlx_pixel_put(env->mlx_ptr, env->win_ptr, 10, env->win_height / 2, 0xFFFFFF); // enlever ca
	mlx_key_hook(env->win_ptr, fdf_key, env);
	

	mlx_loop(env->mlx_ptr);

	return (1);
}
