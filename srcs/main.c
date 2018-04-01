#include "../includes/fdf.h"

int		test(void)
{
	ft_putchar('D');
	return (1);
}

int main(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2) // gerer lerreur correctement
		return (0);
	env = initialize_env();
	env->array = read_map(env, argv);
	ft_printf("width = %d et height = %d\n", env->map_width, env->map_height);
	ft_rint_tab(env->array, env->map_height, env->map_width);
	fdf(env);

	return (0);
}
