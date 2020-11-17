#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

void	ft_putnbr_fd(long int n, int fd);

void	ft_putstr_fd(char *s, int fd);

size_t	ft_strlen(const char *s);

void	ft_putchar_fd(char c, int fd);

void	ft_reverse(char s[]);

void	ft_print_hex_big(int n);

void	ft_print_hex_little(int n);

void	ft_print_unsigned_int(int a);

void	ft_print_adress(void *a);

#endif
