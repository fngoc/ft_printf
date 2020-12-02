#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h> /* Для printf */

typedef struct		s_parser
{
	char			flags;
	int				width;
	char			dot;
	int				accuracy;
	char			type;

	int				count;
	va_list			ap;

	char			tap;
	char			check_for_str;
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

void				ft_putnbr_fd(long int n, int fd, t_parser *p);

void 				ft_newtparser(t_parser *p);

void				ft_print_d_or_i(t_parser *p);

void				ft_print_c(t_parser *p);

void				ft_print_s(t_parser *p);

void				ft_check(t_parser *p);

void				ft_putstr_fd_mod(char *s, int fd, t_parser *p);

void				ft_putstr_fd_mod_col(char *s, int fd, t_parser *p, int col);

void				ft_ifnumnul(t_parser *p, int number);

void				ft_print_percent(t_parser *p);

void				ft_print_p(t_parser *p);

void				ft_print_x_or_X(t_parser *p);

void				ft_print_u(t_parser *p);

void				ft_process(t_parser *p, int number);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				ft_make_address(char *address, char *result);

void				ft_bzero(void *s, size_t n);

void				ft_process_u(t_parser *p, unsigned int number);

int					ft_digit_num_u(unsigned int n);

void				ft_reverse(char *s);

void				ft_process_x_or_X(t_parser *p, char *str);

void				ft_print_s_utils_one(t_parser *p, char *str);

void				ft_print_s_utils_two(t_parser *p, char *str);

void				ft_print_s_utils_three(t_parser *p, char *str);

#endif
