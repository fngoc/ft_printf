/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_or_X.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:59:45 by fngoc             #+#    #+#             */
/*   Updated: 2020/12/03 11:59:45 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** dec_to_hex: переводит из 10 в 16 систему
** счисления в зависимости от флага меняется размер букв.
*/

static void	dec_to_hex(char *str, long int l, int flag)
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
** ft_print_x_two: если флаг '0' или флагов нет.
*/

static void	ft_print_x_two(t_parser *p, char *str)
{
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	ft_putstr_fd_mod(str, 1, p);
}

/*
** ft_print_x_one: если флаг '-'.
*/

static void	ft_print_x_one(t_parser *p, char *str)
{
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	ft_putstr_fd_mod(str, 1, p);
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
}

/*
** ft_print_x_zero: если 0.
*/

static void	ft_print_x_zero(t_parser *p)
{
	if (p->flags == '-')
	{
		if (p->accuracy == 0 && p->dot != '.')
			ft_putchar_fd_mod('0', 1, p->accuracy + 1, p);
		else
			ft_putchar_fd_mod('0', 1, p->accuracy, p);
		if (p->width == 0 && p->accuracy == 0)
			ft_putchar_fd('0', 1, p);
		if (p->width > 0 && p->dot != '.' && p->accuracy == 0)
			ft_putchar_fd_mod(p->tap, 1, p->width - 1, p);
		else
			ft_putchar_fd_mod(p->tap, 1, p->width, p);
	}
	else
	{
		if (p->width > 0 && p->dot != '.' && p->accuracy == 0)
			ft_putchar_fd_mod(p->tap, 1, p->width - 1, p);
		else
			ft_putchar_fd_mod(p->tap, 1, p->width, p);
		if (p->accuracy == 0 && p->dot != '.')
			ft_putchar_fd_mod('0', 1, p->accuracy + 1, p);
		else
			ft_putchar_fd_mod('0', 1, p->accuracy, p);
		if (p->width == 0 && p->accuracy == 0)
			ft_putchar_fd('0', 1, p);
	}
}

/*
** ft_print_x: выводит в 16 сичтеме счисления.
*/

void		ft_print_x(t_parser *p)
{
	long int	number;
	int			flag;
	char		buf[20];

	flag = 0;
	number = va_arg(p->ap, long int);
	if (p->dot == '.' && p->width == 0 && p->accuracy == 0)
		return ;
	if (p->type == 'x')
		dec_to_hex(buf, number, flag);
	else
		dec_to_hex(buf, number, ++flag);
	ft_process_x(p, buf);
	if (!number)
	{
		ft_print_x_zero(p);
		return ;
	}
	if (p->flags == '-')
		ft_print_x_one(p, buf);
	else
		ft_print_x_two(p, buf);
}
