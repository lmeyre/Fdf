#include "fdf.h"




void	mlx_join_point_percent(t_env *env, int percent) // on va faire , on parcourst tout les point et pour chqaue point on fait un lien avec celui qui est en bas + a droite
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

	int val_x2;
	int val_y2;
	while (i < env->map_height) // i = y
	{
		while (j < LST->lenght) // j=  x
		{
			val_x = j * env->spacing;
			val_y = i * env->spacing;
			int tmpp;
			val_x2 = (j + 1) * env->spacing;
			val_y2 = (i + 1) * env->spacing;

			if ((j + 1) < LST->lenght)
			{
				tmpp = (val_x - val_y) - val_x; // on met pas decale_x car faudrait lajouter le soustraire des deux camps
				env->pt1_x = val_x + (tmpp * percent / 100) + env->decale_x;

				tmpp = ((val_y + val_x) / 2) - val_y;
				env->pt1_y = val_y + (tmpp* percent / 100) + env->decale_y - (env->array[i][j] * height) * percent / 100; // !!!

				tmpp = (val_x2 - val_y) - val_x2;
				env->pt2_x = val_x2 + ( tmpp* percent / 100) + env->decale_x;

				tmpp = ((val_y + val_x2) / 2) - val_y;
				env->pt2_y = val_y + (tmpp * percent / 100) + env->decale_y - (env->array[i][j + 1] * height) * percent / 100; // !!!


				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i][j + 1]);
				ft_bresenham(env);
				//image_set_pixel(env, env->pt1_x, env->pt1_y, 0xFFFFFF);
				//image_set_pixel(env, env->pt2_x, env->pt2_y, 0xFFFFFF);
			}
			if ((i + 1) < env->map_height && (env->lst->next && (j < ((t_valist*)(env->lst->next->content))->lenght))) // bien verifier celle la particluierement
			{
				tmpp = (val_x - val_y) - val_x;
				env->pt1_x = val_x + (tmpp* percent / 100) + env->decale_x;

				tmpp = ((val_y + val_x) / 2) - val_y;
				env->pt1_y = val_y + (tmpp* percent / 100) + env->decale_y - (env->array[i][j] * height) * percent / 100; // !!!

				tmpp = (val_x - val_y2) - val_x;
				env->pt2_x = val_x + ( tmpp* percent / 100) + env->decale_x;

				tmpp = ((val_y2 + val_x) / 2) - val_y2;
				env->pt2_y = val_y2 + (tmpp * percent / 100) + env->decale_y - (env->array[i + 1][j] * height) * percent / 100; // !!!
			
			
				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i + 1][j]);
				
				ft_bresenham(env);
				//image_set_pixel(env, env->pt1_x, env->pt1_y, 0xFFFFFF);
				//image_set_pixel(env, env->pt2_x, env->pt2_y, 0xFFFFFF);
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

void		join_100(t_env *env, int key)
{
	static int tmp = 1;

	if (env->anim_val > 100)
	{
		tmp = 1;
		new_image(env);
		return ;
	}
	if (env->anim_val <= 0)
		tmp = -1;
//	else if (i >= 100)
//		tmp = 1;
	if (tmp == 1)
		--env->anim_val;
	else if (tmp == -1)
		++env->anim_val;
	/*if ((tmp == Q || tmp == W) && key != Q && key != W)
		i = 100;
	else if ((tmp == Z || tmp == X) && key != Z && key != X)
		i = 100;
	tmp = key;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
    if (env->img)
        ft_bzero(env->img, env->win_width * env->win_height * 4);
	if (key == W)
	{
		 i += 2;
		 mlx_join_point_percent(env, i);
	}
	else if (key == Q)
	{
		i -= 2;
		mlx_join_point_percent(env, i);
	}
	else if (key == Z)
	{
		i -= 2;
		mlx_join_point_percent_effect(env, i);
	}
	else if (key == X)
	{
		i += 2;
		mlx_join_point_percent_effect(env, i);
	}*/
	//if (i == 0)
	//	++i;
	//
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	if (env->img)
        ft_bzero(env->img, env->win_width * env->win_height * 4);
	if (key == W)
		mlx_join_point_percent(env, env->anim_val);
	else if (key == Q)
		mlx_join_point_percent_effect(env, env->anim_val);
	//
	mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);
		//sleep(1);
	int usleep(useconds_t usec);
	//	i += 1;
//	}
/*	mlx_clear_window(env->mlx_ptr, env->win_ptr);
    if (env->img)
        ft_bzero(env->img, env->win_width * env->win_height * 4);
	mlx_join_point_percent(env, i);
	mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);*/
}

int        animate_isometric(t_env *env)
{
	join_100(env, W);
	return (0);
}


