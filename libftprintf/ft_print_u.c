#include "libftprintf.h"

/*
** ft_print_u_two: если флаг '0' или флагов нет.
*/

static void ft_print_u_two(t_parser *p, long int number, int old_width)
{
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!(number == 0 && p->dot == '.' && p->accuracy == 0))
		ft_putnbr_fd(number, 1, p);
	else
	{
		if (p->width != old_width)
			ft_putchar_fd(' ', 1, p);
	}
}

/*
** ft_print_u_one: если флаг '-'.
*/

static void ft_print_u_one(t_parser *p, long int number, int old_width)
{
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!(number == 0 && p->dot == '.' && p->accuracy == 0))
		ft_putnbr_fd(number, 1, p);
	else
	{
		if (p->width != old_width)
			ft_putchar_fd(' ', 1, p);
	}
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
}

/*
** ft_print_u: печать типа u.
*/

void	ft_print_u(t_parser *p)
{
	unsigned int number;
	int old_width;

	old_width = p->width;
	ft_check(p);
	number = va_arg(p->ap, unsigned int);
	if (p->width == 0 && p->accuracy == 0
		&& number == 0 && p->dot == '.')
		return ;
	ft_process_u(p, number);
	if (p->flags == '-')
		ft_print_u_one(p, number, old_width);
	else
		ft_print_u_two(p, number, old_width);
}
