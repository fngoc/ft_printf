/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:41:48 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:01:20 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_process_p_norm: функция для нормы.
*/

static void	ft_process_p_norm(t_parser *p, char *str)
{
	if (p->width > (ft_strlen(str) + p->accuracy))
	{
		p->width = p->width - (ft_strlen(str) + p->accuracy);
		p->tap = ' ';
	}
	else
		p->width = 0;
}

/*
** ft_process_p: установка значений в ширину
** и точность .
*/

void		ft_process_p(t_parser *p, char *str)
{
	if (p->dot == '.')
	{
		p->tap = ' ';
		if (p->accuracy >= ft_strlen(str))
		{
			p->accuracy = p->accuracy - ft_strlen(str) + 2;
			p->dot = (p->accuracy > 0);
		}
		else
			p->accuracy = 0;
	}
	ft_process_p_norm(p, str);
}
