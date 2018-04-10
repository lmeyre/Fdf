#include "fdf.h"


// on va faire une boucle qui assigne des valeur source X source Y destination X dest Y dans une boucle pour tout les liens qu on veut faire, et dedans on appelle bresenham avec DX DX SX SY

static int fake_trace(t_env *env, int fault, int dx, int dy)
{
    int count;
    int curr_x;
    int curr_y;

    count = 0;
    curr_x = env->pt1_x;
    curr_y = env->pt1_y;
    while (1)
    {
        if (curr_x == env->pt2_x && curr_y == env->pt2_y)
        {
           return (count);
        }
        if (env->path == 1)
        {
            (env->scale_x == 1) ? ++curr_x : --curr_x;
            fault -= dy;
            if (fault < 0) // et egal ? si on a bug tester avec
            {
                fault += dx;
                (env->scale_y == 1) ? ++curr_y : --curr_y;
            }
        }
        else
        {
            (env->scale_y == 1) ? ++curr_y : --curr_y;
            fault -= dx;
            if (fault < 0) // et egal ? si on a bug tester avec
            {
                fault += dy;
                (env->scale_x == 1) ? ++curr_x : --curr_x;
            }
        }
        ++count;
    }
}

static void bres_trace(t_env *env)
{
    int     curr_x;
    int     curr_y;
    int     new_color;
    int     final_color;
    int     height;
    int     color_diff;

    curr_x = env->pt1_x;
    curr_y = env->pt1_y;
    height = env->spacing * env->multiply;
    new_color = color_manage(env->start_z * height);
    final_color = color_manage(env->end_z * height);
    env->tmp = fake_trace(env, env->fault, env->dx, env->dy);
    color_diff = ft_abs(new_color - final_color) / env->tmp;
    while (1)
    {
        new_color += color_diff;
        mlx_pixel_put(env->mlx_ptr, env->win_ptr, curr_x, curr_y , final_color);
        if (curr_x == env->pt2_x && curr_y == env->pt2_y)
        {
           // ft_printf("Un trace de fait\n");
            break ;
        }
        if (env->path == 1)
        {
            (env->scale_x == 1) ? ++curr_x : --curr_x;
            env->fault -= env->dy;
            if (env->fault < 0) // et egal ? si on a bug tester avec
            {
                env->fault += env->dx;
                (env->scale_y == 1) ? ++curr_y : --curr_y;
            }
        }
        else
        {
            (env->scale_y == 1) ? ++curr_y : --curr_y;
            env->fault -= env->dx;
            if (env->fault < 0) // et egal ? si on a bug tester avec
            {
                env->fault += env->dy;
                (env->scale_x == 1) ? ++curr_x : --curr_x;
            }
        }
    }
}

static void diff_bres_value(t_env *env)
{
    env->dx = ft_abs(env->pt1_x - env->pt2_x);
    env->dy = ft_abs(env->pt1_y - env->pt2_y);
    env->path = (env->dx < env->dy ? env->dy : env->dx);
    env->scale_x = (env->pt1_x < env->pt2_x ? 1 : -1);
    env->scale_y = (env->pt1_y < env->pt2_y ? 1 : -1);
    env->fault = env->path/ 2;
    env->path = (env->dx < env->dy ? -1 : 1); // path = 1 si x est le plus grand sinon - 1 pour y
   // ft_printf("env paht = %d, scale x = %d, scale y = %d, dx = %d, dy = %d\n", env->path, env->scale_x, env->scale_y, env->dx, env->dy);
}

static void perfect_center(t_env *env) // si on veut un centre vraiment parfait il faudra faire plus
{
    int valx;
    int valy;
    int end_x;
    int end_y;

    valx = ((env->map_width - 1) * env->spacing);
    valy = ((env->map_height - 1) * env->spacing);
    end_x = valx - valy;
    end_y = (valx + valy) / 2;
    env->add_x = env->win_width / 2 - end_x; // rajouter scale X si soucis, en fait je crois que scale X a rien a voir du tout avec tout ca
    env->add_y = env->win_height / 2 - end_y;
   
}

void    ft_bresenham(t_env *env)
{
    diff_bres_value(env);
    if (env->center != env->spacing)
    {
        perfect_center(env);
        env->center = env->spacing;
    }
        env->pt1_x += env->add_x;
        env->pt2_x += env->add_x;
        env->pt1_y += env->add_y;
        env->pt2_y += env->add_y;
    //ft_printf("dx = %d et dy = %d\n La position initiale x %d et y %d et cible x %d et y %d\n", env->dx, env->dy,env->pt1_x,env->pt1_y,env->pt2_x,env->pt2_y);
    bres_trace(env);
}