/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:17:29 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/23 01:17:43 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2) // gerer lerreur correctement
		return (0);
	env = initialize_env();
	read_map(env, argv);
	fdf(env);
	return (0);
}

int			read_map(t_env *env, char **argv)
{
	int	fd;

	get_map_dimension(argv, env, 0, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	get_map_value(fd, env, 0, 0);
	close(fd);
	return (1);
}
