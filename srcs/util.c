#include "fdf.h"
#include <math.h>

void     help_value(int value, t_env *env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < env->map_height)
	{
		while (j < LST->lenght)
		{
            if (env->origin_array[i][j] != 0)
                env->array[i][j] += value;
            ++j;
        }
        ++i;
        j = 0;
    }
}

void    man_write(t_env *env)
{
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10 , 0xFFFFFF, "PAD to move -> 1/2/3/4/6/7/8/9");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 30 , 0xFFFFFF, "Arrow keys to change height -> Up & Down");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 50 , 0xFFFFFF, "Zoom -> + & -");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70 , 0xFFFFFF, "Multiply height -> O & L");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 90 , 0xFFFFFF, "Reset -> Space");
}

int color_manage(double t) // si on a un soucis ca peut venir du cast
{
    return ((RGB(
        127.5 * (cos(t) + 1),
        127.5 * (sin(t) + 1),
        127.5 * (1 - cos(t)))));
}