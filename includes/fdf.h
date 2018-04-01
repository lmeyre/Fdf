#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "../libft/includes/libft.h"

typedef struct      s_env
{
	int				**array;
	int				map_width;
	int				map_height;
	int				win_width;
	int				win_height;
	void			*mlx_ptr;
	void			*win_ptr;
	int				pt1_x;
	int				pt1_y;
	int				pt2_x;
	int				pt2_y;
	int				dx;
	int				dy;
	int				scale_x;
	int				scale_y;
	int				fault;
	int				path;

}                   t_env;

t_env       *initialize_env(void);

int		test(void);

int			**read_map(t_env *env, char **argv);
int			fdf(t_env *env);
int			mlx_fdf(t_env *env);
void    	ft_bresenham(t_env *env);

#endif
