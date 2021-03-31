#include "libftprintf.h"

/*
** fr_print_c_two: если флаг '0'.
*/

static void	fr_print_c_two(t_parser *p, char ch)
{
	if (p->width == 0)
	{
		ft_putchar_fd(ch, 1, p);
		return ;
	}
	ft_putchar_fd_mod('0', 1, p->width - 1, p);
	ft_putchar_fd(ch, 1, p);
}

/*
** fr_print_c_one: если флаг '-'.
*/

static void	fr_print_c_one(t_parser *p, char ch)
{
	if (p->width == 0)
	{
		ft_putchar_fd(ch, 1, p);
		return ;
	}
	ft_putchar_fd(ch, 1, p);
	ft_putchar_fd_mod(' ', 1, p->width - 1, p);
}

/*
** ft_print_c: печать типа c.
*/

void		ft_print_c(t_parser *p)
{
	char	ch;

	ch = va_arg(p->ap, int);
	if (p->flags == '-')
	{
		fr_print_c_one(p, ch);
		return ;
	}
	else if (p->flags == '0')
	{
		fr_print_c_two(p, ch);
		return ;
	}
	if (p->width != 0)
		ft_putchar_fd_mod(' ', 1, p->width - 1, p);
	ft_putchar_fd(ch, 1, p);
}
