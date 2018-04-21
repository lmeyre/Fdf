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

static void manage_color(t_env *env, int height, int *count, int *color)// ptet si on gere mieux les variable au dessus on evitera de refaire les appele de variable en boucle ici et faire lag
{
    int     base_color;
    int     final_color;
    int     difference;
    int     amount;

    
    (void) height;
    return ;
    base_color = (env->color_max * env->start_z / 15) + (env->color_max * env->start_z % 15) + 0xFFFFFF;
    final_color = (env->color_max * env->end_z / 15) + (env->color_max * env->end_z % 15) + 0xFFFFFF;
    if (base_color == final_color)
        return ;
    amount = fake_trace(env, env->fault, env->dx, env->dy);// donner cette valeur au dessus pour moins faire lag en la recalculant
    difference = ft_abs(base_color - final_color);//idem
   // if (*count == amount / difference && amount - env->tmpdebug >= 10)
   // {  
      //  ft_printf("on change de couleur pendant brese\n amount = %d, diff = %d, count = %d\n", amount, difference, *count);
        if (env->color < 0 && base_color > final_color)
            *color -= difference / amount;
        else if (env->color > 0 && base_color > final_color)
            *color += difference / amount;

        //*color += difference / amount;
        env->color = 0;/*color_manage(*color / 10)*/;
      (void) count;
       // *count = 0;
   // }
}

static void bres_trace(t_env *env)
{
    int     curr_x;
    int     curr_y;
    int     height;
    int     count;
    int     color_start;


  //  int     color_diff;

    curr_x = env->pt1_x;
    curr_y = env->pt1_y;
    // bug si spacing est egal a 0 voir comment on a fait dans mlx mais sans creer de soucis
    height = 10;
    /*env->tmp = fake_trace(env, env->fault, env->dx, env->dy);
    if (new_color == final_color)
        color_diff = 0;
    else
        color_diff = (new_color - final_color) / env->tmp;*/
        count = 0;
    env->color = 0;
    //if (env->start_z != 0)
        color_start = (env->color_max * env->start_z / 15) + (env->color_max * env->start_z % 15) + 0xFFFFFF;
    //else
        //color_start = 0xFFFFFF;
    //env->color = 0xC6ECF;
    env->tmpdebug = 0;
    while (1)
    {
        manage_color(env, height, &count, &color_start);
        //if (tmp  != env->color )
            //return ;
        //new_color += color_diff;
        //mlx_pixel_put(env->mlx_ptr, env->win_ptr, curr_x, curr_y , env->color);
        image_set_pixel(env, curr_x, curr_y, env->color_max);
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
                (env->scale_y == 1) ? ++(env->color) : --(env->color);//verifier mais a priori oui on up dans les deux sens car on sait si on ajoute ou soustrait color aapres dans manage
            }
        }
        else
        {
            (env->scale_y == 1) ? ++curr_y : --curr_y;
            (env->scale_y == 1) ? ++(env->color) : --(env->color);
            env->fault -= env->dx;
            if (env->fault < 0) // et egal ? si on a bug tester avec
            {
                env->fault += env->dy;
                (env->scale_x == 1) ? ++curr_x : --curr_x;
            }
        }
        ++env->tmpdebug;
    }
}

static void diff_bres_value(t_env *env)
{
    env->dx = ft_abs(env->pt1_x - env->pt2_x);
    env->dy = ft_abs(env->pt1_y - env->pt2_y);
    env->path = (env->dx < env->dy ? env->dy : env->dx);
    env->scale_x = (env->pt1_x < env->pt2_x ? 1 : -1);
    env->scale_y = (env->pt1_y < env->pt2_y ? 1 : -1);
    env->fault = env->path / 2;
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
    env->add_x = env->win_width / 2 - end_x / 2;
    env->add_y = env->win_height / 2 - end_y / 2;
}

void    ft_bresenham(t_env *env)
{
    diff_bres_value(env);
    if (env->center != env->spacing)
    {
        perfect_center(env);
        env->center = env->spacing; // peut etre ps compatible avec animation
    }
        env->pt1_x += env->add_x;
        env->pt2_x += env->add_x;
        env->pt1_y += env->add_y;
        env->pt2_y += env->add_y;
    //ft_printf("dx = %d et dy = %d\n La position initiale x %d et y %d et cible x %d et y %d\n", env->dx, env->dy,env->pt1_x,env->pt1_y,env->pt2_x,env->pt2_y);
    bres_trace(env);
}