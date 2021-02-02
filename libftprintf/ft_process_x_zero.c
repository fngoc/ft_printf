/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:23:26 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:01:33 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_process_x_zero: установка значений в ширину
** и точность если number == 0.
*/

void	ft_process_x_zero(t_parser *p)
{
	if (p->dot == '.')
	{
		p->tap = ' ';
		if (p->accuracy < 0)
			p->accuracy = 0;
		else if (p->accuracy >= 1)
		{
			p->accuracy = p->accuracy - 1;
			p->dot = (p->accuracy > 0);
		}
	}
	if (p->width > (1 + p->accuracy))
		p->width = p->width - (1 + p->accuracy);
	else
		p->width = 0;
}
