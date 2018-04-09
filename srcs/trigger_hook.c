#include "../includes/fdf.h" // a changer mais on le garde pour rendre visual content

static void            key_moove(int key, t_env *env)
{
    if (key == PAD_TWO)
        env->decale_y += MOOVE_INTENSITY; // VOIR TOUTES LES VARIABLE COMME LE 2 DANS CE FICHIER
    else if (key == PAD_EIGHT)
        env->decale_y -= MOOVE_INTENSITY;
    else if (key == PAD_SIX)
        env->decale_x += MOOVE_INTENSITY;
    else if (key == PAD_FOUR)
        env->decale_x -= MOOVE_INTENSITY;
    else if (key == PAD_ONE)
        {
            env->decale_y += MOOVE_INTENSITY; //a partir de la tester si on doit mettre la moitie ou juste un
            env->decale_x -= MOOVE_INTENSITY;
        }
    else if (key == PAD_THREE)
        {
            env->decale_y += MOOVE_INTENSITY;
            env->decale_x += MOOVE_INTENSITY;
        }
    else if (key == PAD_SEVEN)
        {
            env->decale_y -= MOOVE_INTENSITY;
            env->decale_x -= MOOVE_INTENSITY;
        }
    else if (key == PAD_NINE)
        {
            env->decale_y -= MOOVE_INTENSITY;
            env->decale_x += MOOVE_INTENSITY;
        }
}

static void            key_zoom(int key, t_env *env)
{

    if (key == MORE)
        env->spacing += 3;
    else if (key == LESS)
        env->spacing -= 3;
}

void            key_height_multiplier(int key, t_env *env)
{
   // ft_printf("On rentre dans multiplier");
    if (key == UP_ARROW)
        env->multiply += 1;
    else if (key == DOWN_ARROW)
        env->multiply -= 1;
}
/*
void            key_reset(t_env *env)
{

}*/


int            fdf_key(int key, t_env *env)
{
  //  ft_printf("On rentre dans key, elle vaut %d\n", key);
    if (key ==  MORE || key == LESS)
    {
       // ft_putendl("1");
        key_zoom(key, env);
    }
    else if (key == PAD_ONE || key == PAD_TWO || key == PAD_THREE || key == PAD_FOUR
    || key == PAD_SIX || key == PAD_SEVEN || key == PAD_EIGHT || key == PAD_NINE)
    {
     //   ft_putendl("22");
        key_moove(key, env);
    }
    else if (key == UP_ARROW || key == DOWN_ARROW)
    {
     //   ft_putendl("3");
        key_height_multiplier(key, env);
    }
    else if (key == ESC)
    {
      //  ft_putendl("4");
        exit(0);
    }
    else if (key == T)
    {
     //   ft_putendl("ici");
        mlx_clear_window(env->mlx_ptr, env->win_ptr);
    }
    else if (key == Y)
    {
        //ft_putendl("la");
        mlx_destroy_window(env->mlx_ptr, env->win_ptr);
    }

    mlx_clear_window(env->mlx_ptr, env->win_ptr);
    //mlx_map_point(env);
	mlx_join_point(env);
    return (0);
}