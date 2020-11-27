#include "libftprintf.h"

/*
** ft_print_d_or_i_four: если ширина > точность и > кол-во символов в числе.
*/

static void ft_print_d_or_i_four(t_parser *p, int number, int digit_num)
{
	if (p->flags == '-')
	{
		if (number < 0)
		{
			ft_putchar_fd_mod('-', 1, 1, p);
			ft_putchar_fd_mod('0', 1, p->number_after_dot - digit_num, p);
			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
			ft_putchar_fd_mod(' ', 1, p->width - p->number_after_dot - 1, p);
		}
		else
		{
			ft_putchar_fd_mod('0', 1, p->number_after_dot - digit_num, p);
			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
			ft_putchar_fd_mod(' ', 1, p->width - p->number_after_dot, p);
		}
		return ;
	}
	if (number < 0)
	{
		ft_putchar_fd_mod(' ', 1, p->width - p->number_after_dot - 1, p);
		ft_putchar_fd_mod('-', 1, 1, p);
		ft_putchar_fd_mod('0', 1, p->number_after_dot - digit_num, p);
		ft_putnbr_fd((number < 0) ? -number : number, 1, p);
	}
	else
	{
		ft_putchar_fd_mod(' ', 1, p->width - p->number_after_dot, p);
		ft_putchar_fd_mod('0', 1, p->number_after_dot - digit_num, p);
		ft_putnbr_fd((number < 0) ? -number : number, 1, p);
	}
}

/*
** ft_print_d_or_i_three: если ширина == точность и > кол-во символов в числе.
*/

static void ft_print_d_or_i_three(t_parser *p, int number, int digit_num)
{
	if (number < 0)
	{
		ft_putchar_fd_mod('-', 1, 1, p);
		ft_putchar_fd_mod('0', 1, p->number_after_dot - digit_num, p);
	}
	else
		ft_putchar_fd_mod('0', 1, p->number_after_dot - digit_num, p);
	ft_putnbr_fd((number < 0) ? -number : number, 1, p);
}

/*
** ft_print_d_or_i_two: если точность > кол-во символов в числе.
*/

static void ft_print_d_or_i_two(t_parser *p, int number, int digit_num)
{
	if (number < 0)
	{
		ft_putchar_fd_mod('-', 1, 1, p);
		ft_putchar_fd_mod('0', 1, p->number_after_dot - digit_num, p);
	}
	else
		ft_putchar_fd_mod('0', 1, p->number_after_dot - digit_num, p);
	ft_putnbr_fd((number < 0) ? -number : number, 1, p);
}

/*
** ft_print_d_or_i_one: если ширина > кол-во символов в числе.
*/

static void ft_print_d_or_i_one(t_parser *p, int number, int digit_num)
{
	if (p->flags == '-')
	{
		if (number < 0)
		{
			ft_putchar_fd_mod('-', 1, 1, p);
			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
			ft_putchar_fd_mod(' ', 1, p->width - digit_num - 1, p);
		}
//		if (p->number_after_dot > p->width)
//		{
//			ft_putchar_fd_mod('0', 1, p->number_after_dot - digit_num, p);
//			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
//			return ;
//		}
		else
		{
			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
			ft_putchar_fd_mod(' ', 1, p->width - digit_num, p);
		}
		return ;
	}
	else if (p->flags == '0')
	{
		if (p->number_after_dot > 0)
		{
			if (number < 0)
			{
				ft_putchar_fd_mod(' ', 1, p->width - digit_num -1, p);
				ft_putchar_fd_mod('-', 1, 1, p);
				ft_putnbr_fd((number < 0) ? -number : number, 1, p);
			}
			else
			{
				ft_putchar_fd_mod(' ', 1, p->width - digit_num, p);
				ft_putnbr_fd((number < 0) ? -number : number, 1, p);
			}
			return ;
		}
		if(number < 0)
		{
			ft_putchar_fd_mod('-', 1, 1, p);
			ft_putchar_fd_mod('0', 1, p->width - digit_num - 1, p);
			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
		}
		else
		{
			ft_putchar_fd_mod('0', 1, p->width - digit_num, p);
			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
		}
		return ;
	}
	if (number < 0)
	{
		ft_putchar_fd_mod(' ', 1, p->width - digit_num - 1, p);
		ft_putchar_fd_mod('-', 1, 1, p);
	}
	else
		ft_putchar_fd_mod(' ', 1, p->width - digit_num, p);
	ft_putnbr_fd((number < 0) ? -number : number, 1, p);
}

/*
** ft_print_d_or_i: печать типа d или i.
*/

void ft_print_d_or_i(t_parser *p)
{
	int number;
	int digit_num;

	ft_chek_width_and_numberafterdot(p);
	number = va_arg(p->ap, int);
	digit_num = (number < 0) ? ft_digit_num(number) - 1 : ft_digit_num(number);
	if (p->chek == 'Y')
	{
		ft_putnbr_fd(number, 1, p);
		return ;
	}
	if (number == 0 && p->dot == '.' && p->width == 0 && p->number_after_dot == 0)
		return ;
	if (number == 0 && p->dot == '.' && p->width != 0 && p->number_after_dot == 0)
	{
		ft_putchar_fd_mod(' ', 1, p->width, p);
		return ;
	}
	if ((p->width == p->number_after_dot) && p->width > digit_num)
	{
		ft_print_d_or_i_three(p, number, digit_num);
		return ;
	}
	if ((p->width > p->number_after_dot) && p->number_after_dot > digit_num)
	{
		ft_print_d_or_i_four(p, number, digit_num);
		return ;
	}
	if (p->width > digit_num)
	{
		ft_print_d_or_i_one(p, number, digit_num);
		return ;
	}
	if (p->number_after_dot > digit_num)
	{
		ft_print_d_or_i_two(p, number, digit_num);
		return ;
	}
	ft_putnbr_fd(number, 1, p);
}
