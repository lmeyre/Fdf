#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "../libft/includes/libft.h"

typedef struct      s_env
{
	int             **array;
	int             map_width;
	int             map_height;
	int				win_width;
	int				win_height;
	void			*mlx_ptr;
	void			*win_ptr;
	int				dest_x;
	int				dest_y;
	int				src_x;
	int				src_y;
	int				diff_x;
	int				diff_y;
	int				path;
	int				fault;

}                   t_env;

t_env       *initialize_env(void);

int		test(void);

int			**read_map(t_env *env, char **argv);
int			fdf(t_env *env);
int			mlx_fdf(t_env *env);

#endif
