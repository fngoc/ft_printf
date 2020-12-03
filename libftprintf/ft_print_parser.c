/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:58:57 by fngoc             #+#    #+#             */
/*   Updated: 2020/12/03 11:58:57 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_print_parser: печать парсера
** в зависимости от типа.
*/

int	ft_print_parser(t_parser *p)
{
	if (p->type == '%')
		ft_print_percent(p);
	if (p->type == 'd' || p->type == 'i')
		ft_print_d_or_i(p);
	if (p->type == 'u')
		ft_print_u(p);
	if (p->type == 'c')
		ft_print_c(p);
	if (p->type == 's')
		ft_print_s(p);
	if (p->type == 'p')
		ft_print_p(p);
	if (p->type == 'x' || p->type == 'X')
		ft_print_x(p);
	return (0);
}
