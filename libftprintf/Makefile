# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 12:00:42 by fngoc             #+#    #+#              #
#    Updated: 2020/12/03 12:00:55 by fngoc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

NAME = libftprintf.a

HEADER = libftprintf.h

SRC = ft_printf.c ft_putnbr_fd.c ft_atoi.c ft_digit_num.c ft_isdigit.c\
		ft_newtparser.c ft_parser.c ft_print_parser.c ft_putchar_fd_mod.c\
		ft_putchar_fd.c ft_print_d_or_i.c ft_print_c.c ft_get_accuracy.c\
		ft_strlen.c ft_putstr_fd_mod.c ft_process_d_or_i.c\
		ft_bzero.c ft_putstr_fd_mod_col.c ft_print_s.c ft_print_percent.c\
		ft_print_p.c ft_print_x.c ft_memcpy.c ft_make_address.c\
		ft_print_u.c ft_digit_num_u.c ft_process_u.c ft_reverse.c\
		ft_process_x.c ft_process_s.c ft_get_width.c ft_process_x_zero.c\
		ft_process_p.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

OPTION = -c

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAG) $(OPTION) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
