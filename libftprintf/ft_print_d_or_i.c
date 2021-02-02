/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_or_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:58:48 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:00:39 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_modul: возвращает модуль числа.
*/

static long	ft_modul(long n)
{
	if (n > 0)
		return (n);
	else
		return (n * -1);
}

/*
** ft_print_d_or_i_one: если флаг '0' или флагов нет.
*/

static void	ft_print_d_or_i_two(t_parser *p, int number, int old_width)
{
	if (number < 0 && p->tap == '0')
		ft_putchar_fd('-', 1, p);
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
	if (number < 0 && p->tap == ' ')
		ft_putchar_fd('-', 1, p);
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!(number == 0 && p->dot == '.' && p->accuracy == 0))
		ft_putnbr_fd(ft_modul(number), 1, p);
	else
	{
		if (p->width != old_width)
			ft_putchar_fd(' ', 1, p);
	}
}

/*
** ft_print_d_or_i_one: если флаг '-'.
*/

static void	ft_print_d_or_i_one(t_parser *p, int number, int old_width)
{
	if (number < 0)
		ft_putchar_fd('-', 1, p);
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!(number == 0 && p->dot == '.' && p->accuracy == 0))
		ft_putnbr_fd(ft_modul(number), 1, p);
	else
	{
		if (p->width != old_width)
			ft_putchar_fd(' ', 1, p);
	}
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
}

/*
** ft_print_d_or_i: печать типа d или i.
*/

void		ft_print_d_or_i(t_parser *p)
{
	int number;
	int old_width;

	old_width = p->width;
	number = va_arg(p->ap, int);
	if (p->width == 0 && p->accuracy == 0
		&& number == 0 && p->dot == '.')
		return ;
	ft_process_d_or_i(p, number);
	if (p->flags == '-')
		ft_print_d_or_i_one(p, number, old_width);
	else
		ft_print_d_or_i_two(p, number, old_width);
}
