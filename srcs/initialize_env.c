#include "../includes/fdf.h"

t_env       *initialize_env(void)
{
    t_env *env;

    env = (t_env*)malloc(sizeof(t_env));
    ft_bzero(env, sizeof(t_env));
    env->array = NULL;
    env->map_width = 0;
    env->map_height = 0;
    env->win_height = 0;
    env->win_width = 0;
    env->pt1_x = 0;
    env->pt2_x = 0;
    env->pt1_y = 0;
    env->pt2_y = 0;
    env->dx = 0;
    env->dy = 0;
    env->scale_x = 0;
    env->scale_y = 0;
    env->fault = 0;
    env->path = 0;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;

    return (env);
}
