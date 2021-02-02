/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:59:09 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:01:05 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** dec_to_hex: переводит из 10 в 16 систему
** счисления в зависимости от флага меняется размер букв.
*/

static void	dec_to_hex(char *str, unsigned int l, int flag)
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
** ft_print_x_zero_norm: для нормы.
*/

static void	ft_print_x_zero_norm(t_parser *p, int old_width)
{
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!(p->dot == '.' && p->accuracy == 0))
		ft_putnbr_fd(0, 1, p);
	else
	{
		if (old_width)
			ft_putchar_fd(' ', 1, p);
	}
}

/*
** ft_print_x_zero: если number == 0.
*/

static void	ft_print_x_zero(t_parser *p)
{
	int	old_width;

	old_width = p->width;
	if (p->width == 0 && p->dot == '.' && p->accuracy == 0)
		return ;
	ft_process_x_zero(p);
	if (p->flags == '-')
	{
		ft_putchar_fd_mod('0', 1, p->accuracy, p);
		if (!(p->dot == '.' && p->accuracy == 0))
			ft_putnbr_fd(0, 1, p);
		else
		{
			if (old_width)
				ft_putchar_fd(' ', 1, p);
		}
		ft_putchar_fd_mod(p->tap, 1, p->width, p);
	}
	else
		ft_print_x_zero_norm(p, old_width);
}

/*
** ft_print_x_norm: функция для нормы.
*/

static void	ft_print_x_norm(t_parser *p, char *buf, unsigned int number)
{
	if (!number)
	{
		ft_print_x_zero(p);
		return ;
	}
	ft_process_x(p, buf);
	if (p->flags == '-')
	{
		ft_putchar_fd_mod('0', 1, p->accuracy, p);
		ft_putstr_fd_mod(buf, 1, p);
		ft_putchar_fd_mod(p->tap, 1, p->width, p);
	}
	else
	{
		ft_putchar_fd_mod(p->tap, 1, p->width, p);
		ft_putchar_fd_mod('0', 1, p->accuracy, p);
		ft_putstr_fd_mod(buf, 1, p);
	}
}

/*
** ft_print_x: выводит в 16 сичтеме счисления.
*/

void		ft_print_x(t_parser *p)
{
	unsigned int	number;
	int				flag;
	char			buf[20];

	flag = 0;
	number = va_arg(p->ap, unsigned int);
	if (p->dot != '.' && p->width == 0 && p->accuracy == 0 && number == 0)
	{
		ft_putchar_fd('0', 1, p);
		return ;
	}
	if (p->type == 'x')
		dec_to_hex(buf, number, flag);
	else
		dec_to_hex(buf, number, ++flag);
	ft_print_x_norm(p, buf, number);
}
