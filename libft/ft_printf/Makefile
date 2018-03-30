FLAG = -Wall -Werror -Wextra

NAME = libftprintf.a

TMP = temp.a

MAKE = Makefile

INCLUDESDIR = includes

HEADER = includes/ft_printf.h

SRCDIR = srcs

SRC = srcs/color.c srcs/attrib.c srcs/global_conversion.c srcs/ft_printf.c srcs/initialize.c srcs/integer_signed_conversion.c srcs/integer_unsigned_conversion.c srcs/precision_field.c srcs/scan.c srcs/unicod_conversion.c

BIN = $(SRC:.c=.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(MAKE) $(BIN) $(HEADER)
	@ar rc $(NAME) $(BIN)

%.o: %.c $(HEADER)
		@gcc -o $@ -c $< -I $(INCLUDESDIR) $(FLAG)

clean:
		@/bin/rm -rf $(BIN)

fclean: clean
		@/bin/rm -rf $(NAME)

re: fclean all
