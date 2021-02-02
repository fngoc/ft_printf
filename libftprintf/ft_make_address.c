/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:58:17 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:00:20 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** dec_to_hex: из 10 в 16 систему.
*/

static void	dec_to_hex(char *str, long int l)
{
	int	i;
	int	ost;

	i = 0;
	ft_bzero(str, 20);
	while (l > 0)
	{
		ost = l % 16;
		if (ost > 9)
			str[i] = 'a' + ost - 10;
		else
			str[i] = '0' + ost;
		l = l / 16;
		++i;
	}
	str[i] = 'x';
	str[++i] = '0';
}

/*
** ft_make_address: делает адресс переменной.
*/

void		ft_make_address(char *address, char *result)
{
	long int	address_long;

	ft_memcpy(&address_long, &address, sizeof(void *));
	dec_to_hex(result, address_long);
	ft_reverse(result);
}
