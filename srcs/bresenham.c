#include "fdf.h"


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
        if (curr_x == env->pt2_x && curr_y == env->pt2_y )
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
   // ft_printf("env paht = %d, scale x = %d, scale y = %d, dx = %d, dy = %d\n", env->path, env->scale_x, env->scale_y, env->dx, env->dy);
}

void    ft_bresenham(t_env *env)
{
    static int x = 42;
    int val_x;
    int val_y;

    diff_bres_value(env);
    if (x != env->spacing)
    {
        val_x = env->map_width * env->spacing;
        val_y = env->map_height * env->spacing;
        ft_printf("decale x = %d et decale y = %d\n", env->decale_x, env->decale_y);
        env->add_x = env->win_width / 2 - ((val_x / 2 - val_y / 2)); // rajouter scale X si soucis
	    env->add_y = (env->win_height / 2) - ((val_y / 2) - ((val_x / 2)) / 2);

     //   ft_printf("add x = %d et add y = %d, pt1 x = %d\n", env->add_x, env->add_y, env->pt1_x);
       // ft_printf("win width = %d height = %d\n", env->win_width, env->win_height);
        x = env->spacing;
    }
            env->pt1_x += env->add_x;
        env->pt2_x += env->add_x;
        env->pt1_y += env->add_y;
        env->pt2_y += env->add_y;
    //ft_printf("dx = %d et dy = %d\n La position initiale x %d et y %d et cible x %d et y %d\n", env->dx, env->dy,env->pt1_x,env->pt1_y,env->pt2_x,env->pt2_y);
    bres_trace(env);
}