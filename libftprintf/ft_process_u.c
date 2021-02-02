/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:59:58 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:01:28 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_process_u: установка значений в ширину
** и точность для unsigned int.
*/

void	ft_process_u(t_parser *p, unsigned int n)
{
	int digit_num;

	if (p->dot == '.')
	{
		p->tap = ' ';
		digit_num = (n < 0) ? ft_digit_num_u(n) - 1 : ft_digit_num_u(n);
		if (p->accuracy >= digit_num)
		{
			p->accuracy = p->accuracy - digit_num;
			p->dot = (p->accuracy > 0);
		}
		else
			p->accuracy = 0;
	}
	digit_num = ft_digit_num_u(n);
	if ((p->accuracy + digit_num) < p->width)
		p->width = p->width - (p->accuracy + digit_num);
	else
		p->width = 0;
}
