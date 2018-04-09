/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 01:55:08 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/09 19:24:20 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../includes/libft.h"
# define BUFF_SIZE 4096

typedef	struct		s_ptf
{
	char			buff[BUFF_SIZE];
	int				index;
	int				index_buff;
	int				size;
	char			*frmt;
	int				dieze;
	int				zero;
	int				neg;
	int				space;
	int				pos;
	int				width;
	int				precision;
	int				precision_on;
	int				hh_char;
	int				h_short;
	int				l_long;
	int				ll_longlong;
	int				j_intmax;
	int				z_size;
}					t_ptf;

int					ft_printf(const char *format, ...);
void				printf_reset_buf(t_ptf *env);
void				printf_ft_putchar_buff(t_ptf *env, char c);
void				printf_ft_putstr_buff(t_ptf *env, char *str);
t_ptf				*printf_initialize_env(void);
void				printf_reset_value(t_ptf *env);
void				printf_init_conv_tab(void (*trigger[])(t_ptf*,
					va_list*, int));
int					printf_launch_scan(t_ptf *env, va_list *ap);
void				printf_attrib_start(t_ptf *env);
void				printf_field_width_start(t_ptf *env);
void				printf_precision_start(t_ptf *env);
void				printf_flag_start(t_ptf *env);
int					printf_convertion_start(t_ptf *env, va_list *ap);
void				printf_handle_space(int *count, int neg, t_ptf *env);
void				printf_handle_pos(t_ptf *env, int number);
void				printf_handle_precision_int(t_ptf *env, int size);
void				printf_handle_precision_str(t_ptf *env, char *str);
void				printf_handle_precision_wstr(t_ptf *env, wchar_t *wstr);
void				printf_handle_width_other(t_ptf *env, int size);
void				printf_handle_width_unicod(t_ptf *env, int size);
void				printf_as_conv(t_ptf *env, va_list *ap, int bigger);
void				printf_ac_conv(t_ptf *env, va_list *ap, int c);
void				printf_percent_conv(t_ptf *env, va_list *ap, int usls);
void				printf_s_conv(t_ptf *env, va_list *ap, int null);
void				printf_d_conv(t_ptf *env, va_list *ap, int count);
void				printf_b_conv(t_ptf *env, va_list *ap, int count);
void				printf_c_conv(t_ptf *env, va_list *ap, int c);
void				printf_base_conv(t_ptf *env, va_list *ap, int big);
void				printf_p_conv(t_ptf *env, va_list *ap, int bigger);
void				printf_check_color(t_ptf *env, const char *format);

#endif
