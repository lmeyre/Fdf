#include "fdf.h"

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
	read_map(env, argv);
	fdf(env);

	return (0);
}
