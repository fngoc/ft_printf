#include "libftprintf.h"

/*
** dec_to_hex: переводит из 10 в 16 систему
** счисления в зависимости от флага меняется размер букв.
*/

static void dec_to_hex(char *str, long int l, int flag)
{
	int i;
	int ost;

	i = 0;
	ft_bzero(str, 20);
	while (l > 0)
	{
		ost = l % 16;
		if (ost > 9)
		{
			if (flag)
				str[i] = 'A' + ost - 10;
			else
				str[i] = 'a' + ost - 10;
		}
		else
			str[i] = '0' + ost;
		l = l / 16;
		++i;
	}
	ft_reverse(str);
}

/*
** ft_print_x_or_X_two: если флаг '0' или флагов нет.
*/

static void ft_print_x_or_X_two(t_parser *p, char *str, int old_width)
{
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!(p->dot == '.' && p->accuracy == 0))
		ft_putstr_fd_mod(str, 1, p);
	else
	{
		if (p->width != old_width)
			ft_putchar_fd(' ', 1, p);
	}
}

/*
** ft_print_x_or_X_one: если флаг '-'.
*/

static void ft_print_x_or_X_one(t_parser *p, char *str, int old_width)
{
	if (p->width == p->accuracy)
	{
		ft_putstr_fd_mod(str, 1, p);
		return ;
	}
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!(p->dot == '.' && p->accuracy == 0))
		ft_putstr_fd_mod(str, 1, p);
	else
	{
		if (p->width != old_width)
			ft_putchar_fd(' ', 1, p);
	}
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
}

/*
** ft_print_x_or_X_zero: если 0.
*/

static void ft_print_x_or_X_zero(t_parser *p, int old_width)
{
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!(p->dot == '.' && p->accuracy == 0))
		ft_putchar_fd('0', 1, p);
	else
	{
		if (p->width != old_width)
			ft_putchar_fd(' ', 1, p);
	}
}

/*
** ft_print_x_or_X: выводит в 16 сичтеме счисления.
*/

void ft_print_x_or_X(t_parser *p)
{
	long int number;
	int flag;
	char buf[20];
	int old_width;

	old_width = p->width;
	flag = 0;
	ft_check(p);
	number = va_arg(p->ap, long int);
	if (!number)
	{
		ft_print_x_or_X_zero(p, old_width);
		return ;
	}
	if (p->type == 'x')
		dec_to_hex(buf, number, flag);
	else
		dec_to_hex(buf, number, flag + 1);
	ft_process_x_or_X(p, buf);
	if (p->flags == '-')
		ft_print_x_or_X_one(p, buf, old_width);
	else
		ft_print_x_or_X_two(p, buf, old_width);
}
