#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_parser
{
	char			flags;
	unsigned int	width;
	char			dot;
	unsigned int	number_after_dot;
	char			type;
}					t_parser;

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

t_parser	ft_parser(char *str);

int	ft_count_not_N_in_p(t_parser p);

#endif
