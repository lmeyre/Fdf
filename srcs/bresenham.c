#include "../includes/fdf.h"


// on va faire une boucle qui assigne des valeur source X source Y destination X dest Y dans une boucle pour tout les liens qu on veut faire, et dedans on appelle bresenham avec DX DX SX SY

static void bres_trace(t_env *env)
{
    int     curr_x;
    int     curr_y;
    
    curr_x = env->pt1_x; //le 10 devrait etre une variable ils aussi utiliser dans mlx
    curr_y = env->pt1_y;
   // printf("curr x at start = %d et curr y at start = %d pt1y = %d et pt2_y = %d pt1x = %d et pt2x = %d\n", curr_x, curr_y, env->pt1_y, env->pt2_y, env->pt1_x, env->pt2_x);
    while (1)
    {
        //ft_printf("stuck?\n");
        if (curr_x == env->pt2_x && curr_y == env->pt2_y )
        {
            ft_printf("Un trace de fait\n");
            break ;
        }
        if (env->path == 1)
        {
            //ft_printf("stuckYY?\n");
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
            //ft_printf("stuckXX?\n");
            (env->scale_y == 1) ? ++curr_y : --curr_y;
            env->fault -= env->dx;
            if (env->fault < 0) // et egal ? si on a bug tester avec
            {
                env->fault += env->dy;
                (env->scale_x == 1) ? ++curr_x : --curr_x;
            }
        }
        mlx_pixel_put(env->mlx_ptr, env->win_ptr, curr_x, curr_y , 0xFFFFFF);
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
}

void    ft_bresenham(t_env *env)
{
    diff_bres_value(env);
    ft_printf("dx = %d et dy = %d\n La position initiale x %d et y %d et cible x %d et y %d\n", env->dx, env->dy,env->pt1_x,env->pt1_y,env->pt2_x,env->pt2_y);
    bres_trace(env);
}