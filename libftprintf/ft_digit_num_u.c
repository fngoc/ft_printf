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
