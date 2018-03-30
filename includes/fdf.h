#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "../libft/includes/libft.h"

typedef struct      s_env
{
    int             **array;
    int             map_width;
    int             map_height;
    


}                   t_env;

t_env       *initialize_env(void);

int			**read_map(t_env *env, char **argv);

#endif
