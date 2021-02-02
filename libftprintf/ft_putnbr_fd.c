/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:00:13 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:01:49 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_putnbr_fd: Выводит целое число 'n'
** в указанный файл дескриптор.
*/

static void	print_symbole(long int n, int fd, t_parser *p)
{
	if (n > 9)
		print_symbole(n / 10, fd, p);
	ft_putchar_fd((n % 10 + '0'), fd, p);
}

void		ft_putnbr_fd(long int n, int fd, t_parser *p)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd, p);
		print_symbole(n * (-1), fd, p);
	}
	else
		print_symbole(n, fd, p);
}
