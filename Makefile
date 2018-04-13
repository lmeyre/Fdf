# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 23:00:43 by lmeyre            #+#    #+#              #
#    Updated: 2018/04/09 18:33:31 by lmeyre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

FLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix srcs/, bresenham.c fdf.c initialize_env.c main.c mlx.c read_map.c trigger_hook.c util.c animation.c fdf_image.c)\

SRCS_DIR = srcs

BIN_DIR = bin

BIN = $(SRCS:.c=.o)

HEADER = includes/fdf.h

HEADER_DIR = includes

LIB = libft/libft.a

LIBDIR = libft

MAKE = Makefile

DEBUG = -g -fsanitize=address

.PHONY: all clean fclean re mrc little_make visi debug

all: $(NAME)

$(NAME): $(BIN) $(LIB) $(HEADER) $(MAKE)
	@ gcc $(FLAGS) -I /usr/local/include -o $(NAME) $(BIN) -L /usr/local/lib/ -I $(LIBDIR) -I $(HEADER_DIR) $(LIB) -lmlx -framework OpenGL -framework AppKit
	@ mv $(BIN) $(BIN_DIR)

%.o: %.c
	@ gcc $(FLAGS) -o $@ -c $< -I $(HEADER_DIR)

$(LIB):
	@ make -C $(LIBDIR)

mrc: little_make clean

little_make: $(BIN) $(HEADER) $(MAKE)
	@ gcc $(FLAGS) -I /usr/local/include -o $(NAME) $(BIN) -L /usr/local/lib/ -I $(LIBDIR) -I $(HEADER_DIR) $(LIB) -lmlx -framework OpenGL -framework AppKit
	@ mv $(BIN) $(BIN_DIR)

visi: $(BIN) $(LIB) $(HEADER) $(MAKE)
	gcc $(FLAGS) -I /usr/local/include -o $(NAME) $(BIN) -L /usr/local/lib/ -I $(LIBDIR) -I $(HEADER_DIR) $(LIB) -lmlx -framework OpenGL -framework AppKit
	mv $(BIN) $(BIN_DIR) 

debug: $(BIN) $(LIB) $(HEADER) $(MAKE)
	@ gcc $(FLAGS) -I /usr/local/include $(DEBUG) -o $(NAME) $(BIN) -L /usr/local/lib/ -I $(LIBDIR) -I $(HEADER_DIR) $(LIB) -lmlx -framework OpenGL -framework AppKit
	@ mv $(BIN) $(BIN_DIR)

clean:
	@ rm -f $(BIN)
	@ make clean -C $(LIBDIR)

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIBDIR)

re: fclean all
