#include "mlx.h"

void	ft_putchar(char c);

int		test(void)
{
	ft_putchar('D');
	return (1);
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "try");
	mlx_pixel_put(mlx_ptr, win_ptr, 400, 400, 0xFFFFFFF);
	mlx_key_hook(win_ptr, test, (void*)0);
	mlx_loop(mlx_ptr);

	return (0);
}
