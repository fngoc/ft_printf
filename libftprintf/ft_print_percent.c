/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:59:00 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:00:51 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** fr_print_percent_two: если флаг '0'.
*/

static void	fr_print_percent_two(t_parser *p, char ch)
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
** fr_print_percent_one: если флаг '-'.
*/

static void	fr_print_percent_one(t_parser *p, char ch)
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
** ft_print_percent: печать %.
*/

void		ft_print_percent(t_parser *p)
{
	char	ch;

	ch = '%';
	if (p->flags == '-')
	{
		fr_print_percent_one(p, ch);
		return ;
	}
	else if (p->flags == '0')
	{
		fr_print_percent_two(p, ch);
		return ;
	}
	if (p->width != 0)
		ft_putchar_fd_mod(' ', 1, p->width - 1, p);
	ft_putchar_fd(ch, 1, p);
}
