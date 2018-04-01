/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:34:28 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/31 18:46:35 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_word_nbr(const char *s, char c)
{
	int i;
	int count;
	int boool;

	boool = 1;
	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			i++;
			boool == 1 ? count++ : boool;
			boool == 1 ? boool-- : boool;
		}
		else if (s[i] == c)
		{
			boool = 1;
			while (s[i] == c)
				i++;
		}
	}
	return (count);
}
