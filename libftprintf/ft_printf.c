/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:59:50 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:01:12 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_printf: читает и выводит свои аргументы
** возвращает кол-во напечатаных символов.
*/

int	ft_printf(const char *format, ...)
{
	t_parser	p;

	p.count = 0;
	va_start(p.ap, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format != '%')
			ft_putchar_fd(*format, 1, &p);
		else
		{
			if (*++format == '%')
				ft_putchar_fd(*format, 1, &p);
			else
			{
				ft_parser((char **)&format, &p);
				ft_print_parser(&p);
			}
		}
		++format;
	}
	va_end(p.ap);
	return (p.count);
}
