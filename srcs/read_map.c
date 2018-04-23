/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:42:03 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 01:12:27 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_map_height(t_env *env, char **argv, int *fd)
{
	char	*str;

	env->tmp = 0;
	str = NULL;
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		exit(EXIT_FAILURE);
	while (get_next_line(*fd, &str))
	{
		++(env->map_height);
		ft_strdel(&str);
	}
	ft_strdel(&str);
	close(*fd);
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		exit(EXIT_FAILURE);
	if (!(env->array = (int**)malloc(sizeof(int*) * (env->map_height)))
	|| !(env->origin_array = (int**)malloc(sizeof(int*) * (env->map_height))))
	{
		close(*fd);
		exit(EXIT_FAILURE);
	}
}

static void		fill_map_dimension(t_env *env, int fd, int *width, char *str)
{
	*width = ft_word_nbr(str, ' ');
	env->map_width = (*width > env->map_width ? *width : env->map_width);
	if (!(env->array[env->tmp] = (int*)malloc(sizeof(int*) * *width))
	|| !(env->origin_array[env->tmp] = (int*)malloc(sizeof(int*) * *width)))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	++env->tmp;
}

void			get_map_dimension(char **argv, t_env *env, int link, int fd)
{
	char		*str;
	int			width;

	get_map_height(env, argv, &fd);
	while (get_next_line(fd, &str))
	{
		fill_map_dimension(env, fd, &width, str);
		ft_strdel(&str);
		if (!(env->lst))
		{
			if (!(env->lst = ft_lst_new(sizeof(t_valist*))))
			{
				close(fd);
				exit(EXIT_FAILURE);
			}
			LST->link = 0;
			LST->lenght = width;
		}
		else
			assign_value(env, width, link);
		++link;
	}
	ft_strdel(&str);
	close(fd);
}

static void		fill_value(t_env *env)
{
	static int x = 42;

	if (x == 42)
	{
		env->map_min = env->tmp;
		env->map_max = env->tmp;
		x = 0;
	}
	else
	{
		env->map_min = (env->tmp < env->map_min ? env->tmp : env->map_min);
		env->map_max = (env->tmp > env->map_max ? env->tmp : env->map_max);
	}
}

void			get_map_value(int fd, t_env *env, int i, int j)
{
	char	*str;
	char	**tab;

	while (get_next_line(fd, &str))
	{
		tab = ft_strsplit(str, ' ');
		while (tab[i])
		{
			env->tmp = ft_atoi(tab[i]);
			fill_value(env);
			env->array[j][i] = env->tmp;
			env->origin_array[j][i] = env->tmp;
			++i;
		}
		ft_free_strtab(&tab);
		++j;
		ft_strdel(&str);
		i = 0;
	}
	ft_strdel(&str);
}
