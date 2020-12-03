/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_accuracy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:55:09 by fngoc             #+#    #+#             */
/*   Updated: 2020/12/03 12:55:09 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_get_accuracy: берет значение accuracy.
*/

void	ft_get_accuracy(t_parser *p)
{
	p->accuracy = va_arg(p->ap, int);
	if (p->accuracy < 0)
	{
		p->dot = 'N';
		p->accuracy = 0;
	}
}
