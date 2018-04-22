#include "fdf.h"


void	mlx_join_point_percent_effect(t_env *env, int percent) // on va faire , on parcourst tout les point et pour chqaue point on fait un lien avec celui qui est en bas + a droite
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
				tmpp = val_x - val_y + env->decale_x;
				env->pt1_x = val_x + (tmpp* percent / 100) + env->decale_x;

				tmpp = (val_y + val_x)  / 2 + env->decale_y - (env->array[i][j] * height);;
				env->pt1_y = val_y + (tmpp* percent / 100) + env->decale_y - (env->array[i][j] * height) * percent / 100; // !!!

				tmpp = val_x2 - val_y + env->decale_x;
				env->pt2_x = val_x2 + ( tmpp* percent / 100) + env->decale_x;

				tmpp = (val_y + val_x2) / 2 + env->decale_y - (env->array[i][j + 1] * height);
				env->pt2_y = val_y + (tmpp * percent / 100) + env->decale_y - (env->array[i][j + 1] * height) * percent / 100; // !!!


				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i][j + 1]);
				ft_bresenham(env);
			}
			if ((i + 1) < env->map_height && (env->lst->next && (j < ((t_valist*)(env->lst->next->content))->lenght))) // bien verifier celle la particluierement
			{
				tmpp = val_x - val_y + env->decale_x;
				env->pt1_x = val_x + (tmpp* percent / 100) + env->decale_x;

				tmpp = (val_y + val_x)  / 2  + env->decale_y - (env->array[i][j] * height);
				env->pt1_y = val_y + (tmpp* percent / 100) + env->decale_y - (env->array[i][j] * height) * percent / 100; // !!!

				tmpp = val_x - val_y2 + env->decale_x;
				env->pt2_x = val_x + ( tmpp* percent / 100) + env->decale_x;

				tmpp = (val_y2 + val_x) / 2 + env->decale_y - (env->array[i + 1][j] * height);
				env->pt2_y = val_y2 + (tmpp * percent / 100) + env->decale_y - (env->array[i + 1][j] * height) * percent / 100; // !!!
			
			
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


int        animate_isometric_effect(t_env *env)
{
	join_100(env, Q);
	return (0);
}