#include "fdf.h"

static void help_initialize(t_env *env)
{
    env->dx = 0;
    env->dy = 0;
    env->decale_x = 0;
    env->decale_y = 0;
    env->spacing = 10;
    env->multiply = 1;
    env->scale_x = 0;
    env->scale_y = 0;
    env->fault = 0;
    env->path = 0;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
    env->tmp = 0;
    env->center = 42;
    env->start_z = 0;
    env->end_z = 0;
    env->bpp = 0;
    env->s_l = 0;
    env->endian = 0;
}

t_env       *initialize_env(void)
{
    t_env *env;

    env = (t_env*)malloc(sizeof(t_env));
    ft_bzero(env, sizeof(t_env));
    env->array = NULL;
    env->origin_array = NULL;
    env->lst = NULL;
    env->map_width = 0;
    env->map_height = 0;
    env->win_height = 0;
    env->win_width = 0;
    env->pt1_x = 0;
    env->pt2_x = 0;
    env->pt1_y = 0;
    env->pt2_y = 0;
    env->add_x = 0;
    env->add_y = 0;
    env->anim_val = 100;
    env->color_option = -1;
    help_initialize(env);
    // ne pas initialize map min et max
    return (env);
}
