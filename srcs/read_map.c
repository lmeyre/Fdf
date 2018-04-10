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

#include "fdf.h"

static int			get_map_dimension(char **argv, t_env *env)
{
	char		*str;
	int			fd;
	t_list		*tmplst;
	int			link;
	int			width;

	env->tmp = 0;
	link = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &str))
	{
		++(env->map_height);
		ft_strdel(&str);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (!(env->array = (int**)malloc(sizeof(int*) * (env->map_height))) || !(env->origin_array = (int**)malloc(sizeof(int*) * (env->map_height))))
		return (0);
	while (get_next_line(fd, &str))
	{
		width = ft_word_nbr(str, ' ');
		env->map_width = (width > env->map_width ? width : env->map_width);
		if (!(env->array[env->tmp] = (int*)malloc(sizeof(int*) * width)) || !(env->origin_array[env->tmp] = (int*)malloc(sizeof(int*) * width))) 
			return (0);
		++env->tmp;
		if (!(env->lst))
		{
			if (!(env->lst = ft_lst_new(sizeof(t_valist*))))
				return (0);
			LST->link = 0;
			LST->lenght = width;
		}
		else
		{
			tmplst = ft_lst_new(sizeof(t_valist*));
			((t_valist*)(tmplst->content))->link = link;
			((t_valist*)(tmplst->content))->lenght = width; 
			ft_lst_add_end(&env->lst, tmplst);
		}
		++link;
		ft_strdel(&str);
	}
	close(fd);// verifier quon close bien et quon sort pas avant des fois au cas ou
	return (1);
}

static void			get_map_value(int fd, t_env *env)
{
	int		i;
	int		j;
	char	*str;
	char	**tab;
	int x;

	x = 42;
	j = 0;
	i = 0;
	while (get_next_line(fd, &str))
	{
		tab = ft_strsplit(str, ' ');
		while (tab[i])
		{
			
			env->tmp = ft_atoi(tab[i]);
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
			env->array[j][i] = env->tmp;
			env->origin_array[j][i] = env->tmp;
			++i;
		}
		free(tab);
		++j;
		ft_strdel(&str);
		i = 0;
	}
}

int			read_map(t_env *env, char **argv)
{
	int	fd;

	if (!(get_map_dimension(argv, env)))
		return (0);
	fd = open(argv[1], O_RDONLY);
	get_map_value(fd, env);
	return (1);
}
