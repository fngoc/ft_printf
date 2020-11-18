.PHONY: all bonus clean fclean re

NAME = libftprintf.a

HEADER = libftprintf.h

SRC = ft_printf.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_putchar_fd.c\
	ft_reverse.c ft_print_hex_big.c ft_print_hex_little.c ft_print_unsigned_int.c\
	ft_print_adress.c ft_atoi.c ft_isdigit.c dec_in_bin.c\
	ft_putstr_fd_print_int_str.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

OPTION = -c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

rebuild: $(SRC)
	gcc -c $(FLAG) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
