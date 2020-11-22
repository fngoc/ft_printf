#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h> // Для printf

typedef struct		s_parser
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	dot;
	unsigned int	number_after_dot;
	unsigned int	type;
}					t_parser;

va_list				ap;

int					count;

t_parser		ft_printf(const char *format, ...);

void	ft_putnbr_fd(long int n, int fd);

void	ft_putstr_fd(char *s, int fd);

size_t	ft_strlen(const char *s);

void	ft_putchar_fd(char c, int fd);

void	ft_reverse(char s[]);

void	ft_print_hex_big(int n);

void	ft_print_hex_little(int n);

void	ft_print_unsigned_int(int a);

void	ft_print_adress(void *a);

int		ft_atoi(const char *str);

int		ft_isdigit(int c);

int		dec_in_bin(int num);

void	ft_putstr_fd_print_int_str(char *s, int fd, int f);

t_parser	ft_parser(char **str);

int		ft_count_not_N_in_p(t_parser p);

int		ft_print_parser(t_parser p);

void	two_arg_d(t_parser p);

void		ft_putnbr_fd_mod(long int n, int fd, int coll_tabs);

void	ft_puttab(int col, int fd);

int		ft_digit_num(int n);

void	two_arg_s(t_parser p);

void	ft_putstr_fd_mod(char *s, int fd, int coll_tabs);

#endif
