#include "fdf.h"

void	image_set_pixel(t_env *env, int x, int y, int color)
{
	if (x < 0 || x >= env->win_width || y < 0 || y >= env->win_height)
		return ;
	*((int*)(env->img + ((x + y * env->win_width) * 4))) = color;
}

void        new_image(t_env *env)
{
    mlx_clear_window(env->mlx_ptr, env->win_ptr);
    if (env->img)
        mlx_destroy_image(env->mlx_ptr, env->img_ptr);
    //    ft_bzero(env->img, env->win_width * env->win_height * 4);//sale voir si on peut pas faire autrement avec destroy ou clear img
    // vraiment verifier tout ca est bizarre
    env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_width, env->win_height);
    //env->img =  mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->s_l), &(env->endian));

    mlx_join_point(env);
    mlx_put_image_to_window(env, env->win_ptr, env->img_ptr, 0, 0);
    man_fdf(env);
}