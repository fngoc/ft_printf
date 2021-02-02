/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:58:22 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 13:00:25 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ft_memcpy: копирует n байт из массива на который
** указывает аргумент src, в массив
** на который указывает аргумент dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dst);
}
