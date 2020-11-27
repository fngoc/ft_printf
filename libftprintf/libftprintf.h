#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h> /* Для printf */

typedef struct		s_parser
{
	unsigned int	flags;
	int				width;
	unsigned int	dot;
	int				number_after_dot;
	unsigned int	type;

	int				count;
	va_list			ap;

	char			chek;
}					t_parser;

int					ft_printf(const char *format, ...);

int					ft_print_parser(t_parser *p);

int					ft_isdigit(int c);

int					ft_digit_num(long int n);

int					ft_atoi(const char *str);

int					ft_strlen(const char *s);

void				ft_putchar_fd(char c, int fd, t_parser *p);

void				ft_parser(char **str, t_parser *parser);

void				ft_putchar_fd_mod(char c, int fd, int coll, t_parser *p);

void				ft_puttab(int col, int fd, t_parser *p);

void				ft_putnbr_fd(int n, int fd, t_parser *p);

void 				ft_newtparser(t_parser *p);

void				ft_print_d_or_i(t_parser *p);

void				ft_print_c(t_parser *p);

void				ft_print_s(t_parser *p);

void				ft_chek_width_and_numberafterdot(t_parser *p);

void				ft_putstr_fd_mod(char *s, int fd, t_parser *p);

void				ft_putstr_fd_mod_col(char *s, int fd, t_parser *p, int col);

void				ft_ifnumnul(t_parser *p, int number);

void				ft_print_percent(t_parser *p);

void				ft_print_p(t_parser *p);

void				ft_print_x(t_parser *p);

#endif
