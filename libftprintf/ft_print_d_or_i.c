#include "libftprintf.h"

/*
** fr_print_d_or_i_two: если точность < ширины.
*/

static void fr_print_d_or_i_two(t_parser *p, int number)
{
	if (p->flags == '-')
	{
		ft_putnbr_fd(number, 1, p);
		ft_putchar_fd_mod(' ', 1, p->width - ft_digit_num(number), p);
		return ;
	}
	if (p->flags == '0')
	{
		if (number < 0)
			ft_putchar_fd_mod('-', 1, 1, p);
		ft_putchar_fd_mod('0', 1, p->width - ft_digit_num(number), p);
	}
	else
	{
		ft_putchar_fd_mod(' ', 1, p->width - ft_digit_num(number), p);
		ft_putnbr_fd(number, 1, p);
		return;
	}
	ft_putnbr_fd((number < 0) ? -number : number, 1, p);
}

/*
** fr_print_d_or_i_one: если точность > кол-во символов в числе.
*/

static void fr_print_d_or_i_one(t_parser *p, int number, int d_c)
{
	if (p->width > p->number_after_dot)
	{
		if (p->flags == '-')
		{
			if (number < 0)
				ft_putchar_fd_mod('-', 1, 1, p);
			ft_putchar_fd_mod('0', 1, (p)->number_after_dot - d_c, p);
			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
			ft_putchar_fd_mod(' ', 1, p->width - p->number_after_dot - ((number < 0) ? 1 : 0), p);
			return ;
		}
		else
		{
			if (number < 0)
				ft_putchar_fd_mod(' ', 1, p->width - p->number_after_dot, p);
			else
				ft_putchar_fd_mod(' ', 1, p->width - p->number_after_dot, p);
		}
	}
	if (number < 0)
		ft_putchar_fd_mod('-', 1, 1, p);
	ft_putchar_fd_mod('0', 1, p->number_after_dot - d_c, p);
	ft_putnbr_fd((number < 0) ? -number : number, 1, p);
}

/*
** ft_print_d_or_i: печать типа d или i.
*/

void ft_print_d_or_i(t_parser *p)
{
	int number;
	int d_c;

	ft_chek_width_and_numberafterdot(p);
	number = va_arg(p->ap, int);
	d_c = (number < 0) ? ft_digit_num(number) - 1 : ft_digit_num(number);
	if (p->number_after_dot > d_c)
	{
		fr_print_d_or_i_one(p, number, d_c);
		return ;
	}
	if (p->width > ft_digit_num(number))
	{
		fr_print_d_or_i_two(p, number);
		return ;
	}
	ft_putnbr_fd(number, 1, p);
}
