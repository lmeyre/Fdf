#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "../libft/includes/libft.h"
# include "define_fdf.h"
# define LST ((t_valist*)(env->lst->content))
//# define DECALE 100 // peut etre a remoove
//# define SPACING 10 // 
//# define MULTIPLY 5 //
# define MOOVE_INTENSITY 10

typedef struct      s_env
{
	int				**array;
	int				**origin_array;
	t_list			*lst;
	int				map_width;
	int				map_height;
	int				win_width;
	int				win_height;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img;
	int				pt1_x;
	int				pt1_y;
	int				pt2_x;
	int				pt2_y;
	int				dx;
	int				dy;
	int				decale_x;
	int				decale_y;
	int				add_x;
	int				add_y;
	int				spacing;
	int				multiply;
	int				scale_x;
	int				scale_y;
	int				fault;
	int				path;
	int				tmp;
	int				center;
	int				color;
	int				map_min;
	int				map_max;
	int				start_z;
	int				end_z;
	int				bpp;
	int				s_l;
	int				endian;
	int				anim_val;
	int				color_option;

}                   t_env;

typedef struct		s_valist
{
	int				link;
	int				lenght;
}					t_valist;

/*
** Utilitaires
*/

t_env       *initialize_env(void);
void     help_value(int value, t_env *env);
void    man_fdf(t_env *env);
int 	color_range(int height);
void            reset_image(t_env *env);

/*
** Images
*/

void        new_image(t_env *env);
void	image_set_pixel(t_env *env, int x, int y, int color);

/*
** fdf
*/

int			fdf(t_env *env);
int			read_map(t_env *env, char **argv);
void		mlx_window_size(t_env *env);
void    	ft_bresenham(t_env *env);
int			fdf_key(int key, t_env *env);
void		mlx_join_point(t_env *env);
int        animate_isometric(t_env *env);
int        animate_isometric_effect(t_env *env);
void		join_100(t_env *env, int key);
void	mlx_join_point_percent(t_env *env, int percent);
void	mlx_join_point_percent_effect(t_env *env, int percent);


#endif
