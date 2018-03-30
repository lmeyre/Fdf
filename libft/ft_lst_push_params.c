/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:20:01 by lmeyre            #+#    #+#             */
/*   Updated: 2017/12/12 22:10:31 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lst_push_params(int argc, char **argv)
{
	int		i;
	t_list	*start;

	if (argc < 2)
		return (NULL);
	i = 1;
	if (!(start = ft_lst_new(sizeof(argv[i]))))
		return (NULL);
	++i;
	while (i < argc)
	{
		ft_lst_add_end(&start, ft_lst_new(sizeof(argv[i])));
		++i;
	}
	return (start);
}
