/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:58:52 by fngoc             #+#    #+#             */
/*   Updated: 2020/12/03 11:58:54 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_print_address_flag_minus: если флаг '-'.
*/

static void	ft_print_address_flag_minus(char *str, t_parser *p, char *address)
{
	ft_putstr_fd_mod("0x", 1, p);
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!address)
		ft_putchar_fd('0', 1, p);
	else
		ft_putstr_fd_mod(&str[2], 1, p);
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
}

/*
** ft_print_address_noflag: если фагов нет.
*/

static void	ft_print_address_noflag(char *str, t_parser *p, char *address)
{
	ft_putchar_fd_mod(p->tap, 1, p->width, p);
	ft_putstr_fd_mod("0x", 1, p);
	ft_putchar_fd_mod('0', 1, p->accuracy, p);
	if (!address)
		ft_putchar_fd('0', 1, p);
	else
		ft_putstr_fd_mod(&str[2], 1, p);
}

/*
** ft_print_p: выводит адрес.
*/

void		ft_print_p(t_parser *p)
{
	void *address;
	char buf[20];

	address = va_arg(p->ap, char *);
	ft_make_address(address, buf);
	ft_process_p(p, buf);
	if (!address && p->width > 0)
		p->width -= (!address);
	if (p->flags == '-')
		ft_print_address_flag_minus(buf, p, address);
	else
		ft_print_address_noflag(buf, p, address);
}
