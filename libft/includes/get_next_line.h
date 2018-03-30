/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:08:32 by lmeyre            #+#    #+#             */
/*   Updated: 2018/02/22 20:29:06 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# define CNTT ((t_fd*)(lst->content))

# include "./libft.h"

typedef struct	s_fd
{
	char		*tmp;
	int			fd;
	struct s_fd	*next;
}				t_fd;

typedef struct	s_filler
{
	int			ret;
	char		*buf;
	int			bool;
	int			boolbis;
	int			lll;
}				t_filler;

int				get_next_line(int fd, char **line);
#endif
