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
    if (key == O)
        env->multiply += 1;
    else if (key == L)
        env->multiply -= 1;
}



void            key_height(int key, t_env *env)
{
    if (key == UP_ARROW)
       help_value(1, env);
    else if (key == DOWN_ARROW)
        help_value(-1, env);
}

void            reset_image(t_env *env)
{
    int i;
    int j;

    i = 0;
    j = 0;
	while (i < env->map_height)
	{
		while (j < LST->lenght)
		{
            env->array[i][j] = env->origin_array[i][j];
			++j;
		}
		if (env->lst->next)
			env->lst = env->lst->next;
		++i;
		j = 0;
	}
    env->center = 42;
    env->decale_x = 0;
    env->decale_y = 0;
    env->spacing = 10;
    env->multiply = 1;
	while (env->lst->prev)
		env->lst = env->lst->prev;
}


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
    else if (key == O || key == L)
    {
     //   ft_putendl("3");
        key_height_multiplier(key, env);
    }
    else if (key == UP_ARROW || key == DOWN_ARROW)
    {
        key_height(key, env);
    }
    else if (key == ESC)
    {
      //  ft_putendl("4");
        exit(0);
    }
    else if (key == W)
    {
        env->anim_val = 100;
        mlx_loop_hook(env->mlx_ptr, animate_isometric, env);
    }
    else if (key == Q)
    {
        env->anim_val = 100;
        mlx_loop_hook(env->mlx_ptr, animate_isometric_effect, env);
    }
    else if (key == SPACEBAR)
    {
        reset_image(env);
    }
    else if (key == C)
    {
        env->color_option *= -1;
    }

    //mlx_clear_window(env->mlx_ptr, env->win_ptr);
    //mlx_map_point(env);
	//mlx_join_point(env);
    //man_fdf(env);
    new_image(env);
    return (0);
}