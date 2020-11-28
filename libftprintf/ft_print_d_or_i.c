#include "libftprintf.h"

/*
** ft_print_d_or_i_one: если нет флагов.
*/

static void ft_print_d_or_i_three(t_parser *p, int number, int digit_num)
{
	if (p->accuracy > p->width)
	{
		if (p->accuracy > digit_num)
		{
			if (number < 0)
				ft_putchar_fd('-', 1, p);
			ft_putchar_fd_mod('0', 1, p->accuracy - digit_num , p);
			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
		}
		else
		{
			if (number < 0)
				ft_putchar_fd('-', 1, p);
			ft_putnbr_fd((number < 0) ? -number : number, 1, p);
		}
	}
	else if (p->width > p->accuracy)
	{
		
	}
	else
		ft_putnbr_fd((number < 0) ? -number : number, 1, p);
}

/*
** ft_print_d_or_i_one: если флаг '0'.
*/

static void ft_print_d_or_i_two(t_parser *p, int number, int digit_num)
{
	
}

/*
** ft_print_d_or_i_one: если флаг '-'.
*/

static void ft_print_d_or_i_one(t_parser *p, int number, int digit_num)
{
	
}

/*
** ft_print_d_or_i: печать типа d или i.
*/

void ft_print_d_or_i(t_parser *p)
{
	int number;
	int digit_num;

	ft_chek_width_and_accuracy(p);
	number = va_arg(p->ap, int);
	digit_num = (number < 0) ? ft_digit_num(number) - 1 : ft_digit_num(number);
	if (p->flags == '-')
		ft_print_d_or_i_one(p, number, digit_num);
	else if (p->flags == '0')
		ft_print_d_or_i_two(p, number, digit_num);
	else
		ft_print_d_or_i_three(p, number, digit_num);
}
