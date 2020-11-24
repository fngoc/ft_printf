.PHONY: all bonus clean fclean re

NAME = libftprintf.a

HEADER = libftprintf.h

SRC = ft_printf.c ft_putnbr_fd.c ft_atoi.c ft_digit_num.c ft_isdigit.c\
		ft_newtparser.c ft_parser.c ft_print_parser.c ft_putchar_fd_mod.c\
		ft_putchar_fd.c ft_puttab.c ft_print_d_or_i.c ft_print_c.c\
		ft_chek_width_and_numberafterdot.c ft_strlen.c ft_putstr_fd_mod.c\
		ft_putstr_fd_mod_col.c ft_print_s.c
		
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
