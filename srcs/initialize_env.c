#include "../includes/fdf.h"

t_env       *initialize_env(void)
{
    t_env *env;

    env = (t_env*)malloc(sizeof(t_env));
    ft_bzero(env, sizeof(t_env));
    env->array = NULL;
    env->map_width = 0;
    env->map_height = 0;

    return (env);
}