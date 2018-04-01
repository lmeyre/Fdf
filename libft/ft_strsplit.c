/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:03:00 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/31 17:35:10 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char			**ft_tab(char **tab, char const *s, int k, int c)
{
	int i;
	int start;

	i = 0;
	while (s[i])
	{
		s[i] == c ? i++ : i;
		if (s[i] != c && s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[k] = ft_strsub(s, start, i - start);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!(s))
		return (0);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (ft_word_nbr(s, c) + 1))))
		return (0);
	tab = ft_tab(tab, s, 0, c);
	return (tab);
}
