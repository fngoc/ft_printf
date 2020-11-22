#include "libftprintf.h"

/*
** two_arg_s: работа с 2 аргументами с типом s.
*/

void	two_arg_s(t_parser p)
{
	int tmp;

	if (p.flags == '-')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (p.width == '*')
	{
		tmp = va_arg(ap, int);
		ft_putstr_fd_mod(va_arg(ap, char *), 1, tmp);
	}
	else
		ft_putstr_fd_mod(va_arg(ap, char *), 1, p.width);
}

/*
** two_arg_d: работа с 2 аргументами с типом d.
*/

void	two_arg_d(t_parser p)
{
	int tmp;

	if (p.flags == '-' || p.flags == '0')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (p.width == '*')
	{
		tmp = va_arg(ap, int);
		ft_putnbr_fd_mod(va_arg(ap, int), 1, tmp);
	}
	else
		ft_putnbr_fd_mod(va_arg(ap, int), 1, p.width);
}
