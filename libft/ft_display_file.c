/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:43:53 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/27 17:25:20 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

#define BUF_SIZE 100

void	ft_display_file(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];

	if (!(argv))
		return ;
	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return ;
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return ;
	}
	fd = open(argv[1], O_RDONLY, S_IREAD);
	if (fd == -1)
		return ;
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	ft_putstr(buf);
}
