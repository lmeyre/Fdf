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
/*	if (env->map_width <= 10) // melange normal car les colonne du tableau sont en largeurs , on a regler le soucis 
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
		env->win_height = env->map_height * 10;*/

	env->win_ptr = mlx_new_window(env->mlx_ptr, /*env->win_width*/500, /*env->win_height*/500, "fdf");// a proteger ?
}

static void mlx_map_point(t_env *env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < env->map_height) // I = =Y
	{
		//ft_printf("lst lenght = %d\n", LST->lenght);
		while (j < LST->lenght) // J = X
		{
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, (j * 10) + 10, (i * 10) + 10, 0xFFFFFF); // premier param est la largeur et le deuxieme la hauteur
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
// NE JAMAIS PARCOURIR LE TABLEAU INT ** EN VERIFIANT QUIL EXISTE CAR INT faire un pomme f verifier quon verifie jamais si env->array existe
static	void	mlx_join_point(t_env *env) // on va faire , on parcourst tout les point et pour chqaue point on fait un lien avec celui qui est en bas + a droite
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < env->map_height) // i = y
	{
		while (j < LST->lenght) // j=  x
		{
			if ((j + 1) < LST->lenght)
			{
				env->pt1_x = j;
				env->pt1_y = i;
				env->pt2_x = j + 1;
				env->pt2_y = i;
				ft_printf("on appelle bresen entre le point X1 = %d et Y1 = %d ET X2 = %d et Y2 = %d\n", env->pt1_x, env->pt1_y, env->pt2_x, env->pt2_y);
				ft_bresenham(env);
			}
			if ((i + 1) < env->map_height && (env->lst->next && (j < ((t_valist*)(env->lst->next->content))->lenght))) // bien verifier celle la particluierement
			{
				env->pt1_x = j;
				env->pt1_y = i;
				env->pt2_x = j;
				env->pt2_y = i + 1;
				ft_printf("on appelle bresen entre le point X1 = %d et Y1 = %d ET X2 = %d et Y2 = %d\n", env->pt1_x, env->pt1_y, env->pt2_x, env->pt2_y);
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
	mlx_map_point(env);
	mlx_join_point(env);
	//env->win_ptr = mlx_new_window(env->mlx_ptr, 800, 800, "try");
	//mlx_pixel_put(env->mlx_ptr, env->win_ptr, 600, 400, 0xFFFFFFF);
	//mlx_key_hook(env->win_ptr, test, (void*)0);
	mlx_loop(env->mlx_ptr);

	return (1);
}
