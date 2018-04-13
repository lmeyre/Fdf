#include "fdf.h"

/*
void        broken_bresenham(t_env *env, char *above, char *isometric)
{

}*/

static void	join_iso_above(t_env *env)
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
			
			if ((j + 1) < LST->lenght) // Dans celui ci uniquament test denlever le +1 MEME QUAND TOUT MARCHERA
			{
				env->pt1_x = val_x - val_y + env->decale_x;
				env->pt1_y = (val_y + val_x) / 2 + env->decale_y  - (env->array[i][j] * height);
				env->pt2_x = val_x + env->decale_x;
				env->pt2_y = val_y + env->decale_y;
				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i][j]);
                //ft_printf("pt1x = %d, 1y = %d 2x = %d 2y = %d\n", env->pt1_x, env->pt1_y, env->pt2_x, env->pt2_y);
				ft_bresenham(env);
			}
			if ((i + 1) < env->map_height && (env->lst->next && (j < ((t_valist*)(env->lst->next->content))->lenght))) // bien verifier celle la particluierement
			{
				env->pt1_x = val_x - val_y + env->decale_x;
				env->pt1_y = (val_y + val_x) / 2 + env->decale_y - (env->array[i][j] * height);
				env->pt2_x = val_x  + env->decale_x;
				env->pt2_y = val_y + env->decale_y;
				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i][j]);
				ft_bresenham(env);
			}
			++j;
            mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);
            //sleep(1);
           /* mlx_clear_window(env->mlx_ptr, env->win_ptr);
            if (env->img)
                mlx_destroy_image(env->mlx_ptr, env->img_ptr);
            env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_width, env->win_height);
            man_fdf(env);*/
		}
		if (env->lst->next)
			env->lst = env->lst->next;
		++i;
		j = 0;
	}
	while (env->lst->prev)
		env->lst = env->lst->prev;
}

void        animate_isometric(t_env *env)
{
    char *isometric;
    char *above;
// eventuellement tout clear avant

    mlx_join_point(env); // bien faire gaffe de la valeur du char * si elle est clear avant que join point mette des trucs dedans
    isometric = env->img;
    mlx_join_point_above(env);
    above = env->img;
    mlx_clear_window(env->mlx_ptr, env->win_ptr);
    if (env->img)
        mlx_destroy_image(env->mlx_ptr, env->img_ptr);
    env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_width, env->win_height);
    join_iso_above(env); // pendant ce join on veut rappeler des mini bresenham donc
    //mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);
}
