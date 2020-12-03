/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_num_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:57:44 by fngoc             #+#    #+#             */
/*   Updated: 2020/12/03 11:57:45 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_digit_num_u: подсчет количества цифр в числе
** для unsigned int.
*/

int		ft_digit_num_u(unsigned int n)
{
	unsigned int tmp;
	unsigned int tmp2;

	tmp2 = n;
	tmp = 1;
	while ((tmp2 = tmp2 / 10))
		++tmp;
	return (tmp);
}
