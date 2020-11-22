#include "libftprintf.h"

/*
** two_arg_u: работа с 2 аргументами с типом p.
*/

void	two_arg_u(t_parser p)
{
	int tmp;

	if (p.flags == '-' || p.flags == '0')
		ft_print_unsigned_int(va_arg(ap, int));
	else if (p.width == '*')
	{
		tmp = va_arg(ap, int);
		ft_print_unsigned_int_mod(va_arg(ap, int), tmp);
	}
	else
		ft_print_unsigned_int_mod(va_arg(ap, int), p.width);
}

/*
** two_arg_p: работа с 2 аргументами с типом p.
*/

void	two_arg_p(t_parser p)
{
	int tmp;

	if (p.flags == '-')
		ft_print_adress(va_arg(ap, void *));
	else if (p.width == '*')
	{
		tmp = va_arg(ap, int);
		ft_print_adress_mod(va_arg(ap, void *), tmp);
	}
	else
		ft_print_adress_mod(va_arg(ap, void *), p.width);
}

/*
** two_arg_c: работа с 2 аргументами с типом c.
*/

void	two_arg_c(t_parser p)
{
	int tmp;

	if (p.flags == '-')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (p.width == '*')
	{
		tmp = va_arg(ap, int);
		ft_putchar_fd_mod(va_arg(ap, int), 1, tmp);
	}
	else
		ft_putchar_fd_mod(va_arg(ap, int), 1, p.width);
}

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
