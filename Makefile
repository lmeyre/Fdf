# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 23:00:43 by lmeyre            #+#    #+#              #
#    Updated: 2018/03/30 16:31:15 by lmeyre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

FLAGS = -Wall -Werror -Wextra

SRC =	 



BIN = $(SRC:.c=.o)

LIB = libft/libft.a

HEADER = includes/push_swap.h

HEADER_DIR = includes/

LIBDIR = libft/

SRCS_DIR = srcs/

MAKE = Makefile

.PHONY: all clean fclean re makec

all: $(NAME)

$(NAME): $(BIN) $(LIB) $(HEADER) $(MAKE)
	@ gcc $(FLAGS) -o $(NAME) $(BIN) -I $(LIBDIR) -I $(HEADER_DIR) $(LIB)

%.o: %.c
	@ gcc $(FLAGS) -o $@ -c $< -I $(HEADER_DIR)


$(LIB):
	@ make -C $(LIBDIR)

clean:
	@ rm -f $(BIN)
	@ make clean -C $(LIBDIR)

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIBDIR)

makec: all clean

re: fclean all
