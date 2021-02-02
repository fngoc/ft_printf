/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:56:41 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:01:23 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_max: сравнение двух чисел.
*/

static int	ft_max(int one, int two)
{
	return ((one > two) ? one : two);
}

/*
** ft_process_s_norm: функция для нормы.
*/

static void	ft_process_s_norm(t_parser *p, char *str)
{
	if (p->width >= p->accuracy)
	{
		if (p->dot == '.')
			p->width = p->width - p->accuracy;
		else
		{
			p->width = ft_max(p->width - ft_strlen(str), 0);
			p->accuracy = ft_strlen(str);
		}
	}
	else
	{
		p->width = 0;
		if (p->dot != '.')
		{
			p->accuracy = 1;
			p->accuracy = ft_strlen(str);
		}
	}
}

/*
** ft_process_s: установка значений в ширину
** и точность для ширины и точности.
*/

void		ft_process_s(t_parser *p, char *str)
{
	if (p->dot == '.')
	{
		if (p->accuracy < 0)
		{
			p->dot = '0';
			p->tap = ' ';
		}
		if (p->accuracy > ft_strlen(str))
			p->accuracy = ft_strlen(str);
	}
	ft_process_s_norm(p, str);
}
