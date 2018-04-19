#include "fdf.h"

/*
void        broken_bresenham(t_env *env, char *above, char *isometric)
{

}*/
/*
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
          //  mlx_clear_window(env->mlx_ptr, env->win_ptr);
         //   if (env->img)
           //     mlx_destroy_image(env->mlx_ptr, env->img_ptr);
            //env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_width, env->win_height);
            //man_fdf(env);
		}
		if (env->lst->next)
			env->lst = env->lst->next;
		++i;
		j = 0;
	}
	while (env->lst->prev)
		env->lst = env->lst->prev;
}*/

static void	mlx_join_point_percent(t_env *env, int percent) // on va faire , on parcourst tout les point et pour chqaue point on fait un lien avec celui qui est en bas + a droite
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
				//
				env->pt1_x = val_x - val_y + env->decale_x;
				env->pt1_y = (val_y + val_x) / 2 + env->decale_y  - (env->array[i][j] * height);
		//		env->pt2_x = val_x + env->decale_x;
		//		env->pt2_y = val_y + env->decale_y;
				//
				env->pt1_x = val_x * 100 - (val_y * percent) + env->decale_x * 100;
				env->pt1_x /= 100;
				env->pt1_y = (val_y * 100 + (val_x * percent)) / (2) + (env->decale_y * 100)  - (env->array[i][j] * height); // !!!
				env->pt1_y /= 100;
				env->pt2_x = ((j + 1) * env->spacing) * 100  - (val_y * percent) + env->decale_x * 100;
				env->pt2_x /= 100;
				env->pt2_y = (val_y * 100 + (((j + 1) * env->spacing) * percent)) / (2) + env->decale_y * 100 - ((env->array[i][j + 1] * height));
				env->pt2_y /= 100;


				env->start_z = (env->array[i][j]);
				env->end_z = (env->array[i][j + 1]);
				ft_bresenham(env);
			}
			if ((i + 1) < env->map_height && (env->lst->next && (j < ((t_valist*)(env->lst->next->content))->lenght))) // bien verifier celle la particluierement
			{
				env->pt1_x = val_x * 100 - (val_y * percent) + env->decale_x * 100;
				env->pt1_x /= 100;
				env->pt1_y = (val_y * 100 + (val_x * percent)) / (2) + env->decale_y * 100 - (env->array[i][j] * height);
				env->pt1_y /= 100;
				env->pt2_x = val_x * 100 - (((i + 1) * env->spacing) * percent) + env->decale_x * 100;
				env->pt2_x /= 100;
				env->pt2_y = ((i + 1) * env->spacing * 100 + (val_x * percent)) / (2) + env->decale_y * 100 - (env->array[i + 1][j] * height);
				env->pt2_y /= 100;
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

void		join_100(t_env *env)
{
	int i;

	i = 1;
	while (i != 100)
	{
		    mlx_clear_window(env->mlx_ptr, env->win_ptr);
    if (env->img)
        ft_bzero(env->img, env->win_width * env->win_height * 4);//sale voir si on peut pas faire autrement avec destroy ou clear img
		mlx_join_point_percent(env, i);
		mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);

			//sleep(1);
			//mlx_loop(env->mlx_ptr);
		
		++i;
	}
	return ;
	    mlx_clear_window(env->mlx_ptr, env->win_ptr);
    if (env->img)
        ft_bzero(env->img, env->win_width * env->win_height * 4);//sale voir si on peut pas faire autrement avec destroy ou clear img
		mlx_join_point_percent(env, i);
	mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);
}

void        animate_isometric(t_env *env)
{
   // char *isometric;
   // char *above;
// eventuellement tout clear avant

   // mlx_join_point(env); // bien faire gaffe de la valeur du char * si elle est clear avant que join point mette des trucs dedans
    //isometric = env->img;
    //mlx_join_point(env);
    //above = env->img;
   // mlx_clear_window(env->mlx_ptr, env->win_ptr);
   // if (env->img)
   //     mlx_destroy_image(env->mlx_ptr, env->img_ptr);
    //env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_width, env->win_height);
	//new_image(env);
	join_100(env);
   // join_iso_above(env); // pendant ce join on veut rappeler des mini bresenham donc
    //mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);
}
