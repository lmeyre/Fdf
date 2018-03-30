#include "../includes/fdf.h"

int		test(void)
{
	ft_putchar('D');
	return (1);
}

int main(int argc, char **argv)
{
	//void *mlx_ptr;
	//void *win_ptr;

	t_env	*env;
	env = initialize_env();
	env->array = read_map(env, argv);
	ft_printf("debut du test\n");
	ft_rint_tab(env->array, env->map_width, env->map_height);
/*
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "try");
	mlx_pixel_put(mlx_ptr, win_ptr, 400, 400, 0xFFFFFFF);
	mlx_key_hook(win_ptr, test, (void*)0);
	mlx_loop(mlx_ptr);
*/
	(void) argc;
	return (0);
}
