# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 14:34:52 by lmeyre            #+#    #+#              #
#    Updated: 2018/03/28 23:35:06 by lmeyre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF = printf.a

PRINTF_DIR = ft_printf

TMP = tmp.a

FLAG = -Wall -Wextra -Werror

SRC = ft_rint_tab.c ft_2d_array.c ft_strcmp_n.c ft_is_integer.c ft_lst_del_all.c ft_lst_create.c get_next_line.c ft_lst_int_copy.c ft_strcmp_c.c ft_lst_getend.c ft_lst_del_last.c ft_lst_del_one.c ft_lst_reverse.c ft_strdel_two.c ft_putwstr.c ft_str_replace.c ft_base_conv.c ft_putwchar.c ft_power.c ft_putlong_unsigned.c ft_itoa_base_unsigned.c ft_putlong.c ft_putnbr_abs.c ft_int_length.c ft_toupper_str.c ft_itoa_base.c ft_strjoin_free.c ft_free_strtab.c ft_strnew_free.c ft_strsearch.c ft_putnbrn.c ft_strdup_free.c ft_strsub_free.c ft_strlen_to.c ft_nbr_of_words.c ft_strtrim_c.c ft_strstr_int.c ft_lst_push_params.c ft_lst_last.c ft_lst_size.c ft_lst_add_end.c ft_swap_str.c ft_display_file.c ft_swap.c ft_sqrt.c ft_sort_params.c ft_recursive_factorial.c ft_range.c ft_print_params.c ft_is_negative.c ft_create_chartab.c ft_rchar_tab.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lst_add.c ft_lstiter.c ft_lst_map.c ft_lst_new.c ft_memalloc.c ft_memchr.c ft_memmove.c ft_memcpy.c ft_memdel.c ft_putchar_fd.c ft_memset.c ft_putendl_fd.c ft_putchar.c ft_putendl.c ft_putnbr_fd.c ft_putstr_fd.c ft_strcat.c ft_strclr.c ft_strcpy.c ft_strequ.c ft_putnbr.c ft_strchr.c ft_putstr.c ft_strdel.c ft_memcmp.c ft_strlen.c ft_strmap.c ft_strncmp.c ft_strnew.c ft_strdup.c ft_strnequ.c ft_strmapi.c ft_strlcat.c ft_strnstr.c ft_strsplit.c ft_strncpy.c ft_strsub.c ft_strncat.c ft_tolower.c ft_strtrim.c ft_toupper.c ft_strstr.c ft_strrchr.c ft_strjoin.c ft_striter.c ft_strcmp.c ft_memccpy.c ft_striteri.c

HEADER = includes/libft.h

INCLUDES = includes

BIN = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF) $(BIN) $(HEADER)
	@ar rc $(TMP) $(BIN)
	@libtool -static -o $(NAME) $(PRINTF_DIR)/libftprintf.a $(TMP)
	@rm -rf $(TMP)
	@ranlib $(NAME)

$(PRINTF):
	@make -C $(PRINTF_DIR)

%.o: %.c $(HEADER)
	@gcc -o $@ -c $< -I $(INCLUDES) $(FLAG)

clean: 
	@/bin/rm -rf $(BIN)
	@ make clean -C $(PRINTF_DIR)

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	@/bin/rm -rf $(NAME)

re: fclean all
