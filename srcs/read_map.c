/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:42:03 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/30 20:42:01 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int			get_map_dimension(int fd)
{
	static int	dimension;
	char		*str;
	char		**tab;

	// gerer si gnl renvoit 0;
	if (dimension == 0)
	{
		get_next_line(fd, &str);
		dimension = ft_word_nbr(str, ' '); // on a modif ici
		ft_strdel(&str);
		return (dimension);
	}
	dimension = 1;
	while (get_next_line(fd, &str))
	{
		++dimension;
		ft_strdel(&str);
	}
	ft_strdel(&str);
	return (dimension);
}

static void			get_map_value(int **array ,int fd)
{
	int		i;
	int		j;
	char	*str;
	char	**tab;

	j = 0;
	i = 0;
	while (get_next_line(fd, &str))
	{
		tab = ft_strsplit(str, ' ');
		while (tab[i])
		{
			array[j][i] = ft_atoi(tab[i]);
			++i;
		}
		free(tab);
		++j;
		ft_strdel(&str);
		i = 0;
	}
}

int			**read_map(t_env *env, char **argv)
{
	int **array;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	env->map_width = get_map_dimension(fd);
	env->map_height = get_map_dimension(fd);
	if (!(array = (int**)ft_2d_array(env->map_height,
								env->map_width, sizeof(int))))
		return (NULL);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	get_map_value(array, fd);
	return (array);
}
