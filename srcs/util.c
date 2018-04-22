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

void    man_fdf(t_env *env)
{
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10 , 0xFFFFFF, "PAD to move -> 1/2/3/4/6/7/8/9");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 30 , 0xFFFFFF, "Arrow keys to change height -> Up & Down");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 50 , 0xFFFFFF, "Zoom -> + & -");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70 , 0xFFFFFF, "Exponential height -> O & L");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 110 , 0xFFFFFF, "Animation/Effect -> Q/T");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 130 , 0xFFFFFF, "Graduate Colors -> C");
    mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 90 , 0xFFFFFF, "Reset -> Space");
}


int color_range(int height)
{
    if (height == 0)
        return (0xFFFFFF);
    int tab_color[12] = {0x0000FF, 0x0077FF, 0x00FFFF, 0x00FF77,
                        0x00FF00, 0x77FF00, 0xFFFF00, 0xFF7700,
                        0xFF0000, 0xFF0077, 0xFF00FF, 0x7700FF};
    if (height > 0)
        while (height > 11)
            height -=12;
    else
        while (height < 0)
            height +=12;
    return (tab_color[height]);
}