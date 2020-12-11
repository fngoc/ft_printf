/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:00:10 by fngoc             #+#    #+#             */
/*   Updated: 2020/12/11 13:00:11 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_process_x: установка значений в ширину и точность.
*/

void	ft_process_x(t_parser *p, char *str)
{
	int len_hex;

	if (p->dot == '.')
	{
		p->tap = ' ';
		len_hex = ft_strlen(str);
		if (p->accuracy >= len_hex)
			p->accuracy = p->accuracy - len_hex;
		else
			p->accuracy = 0;
	}
	len_hex = ft_strlen(str);
	if ((p->accuracy + len_hex) < p->width)
		p->width = p->width - (p->accuracy + len_hex);
	else
		p->width = 0;
}
