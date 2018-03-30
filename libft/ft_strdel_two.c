/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:48:53 by lmeyre            #+#    #+#             */
/*   Updated: 2018/01/24 22:48:54 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strdel_two(char **as, char **asbis)
{
	if (as == NULL || !(*as))
		return ;
	free(*as);
	*as = NULL;
	if (asbis == NULL || !(*asbis))
		return ;
	free(*asbis);
	*asbis = NULL;
}
