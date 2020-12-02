#include "libftprintf.h"

/*
** ft_process_u: установка значений в ширину
** и точность для unsigned int.
*/

void	ft_process_u(t_parser *p, unsigned int number)
{
	int digit_num;

	if (p->dot == '.')
	{
		p->tap = ' ';
		digit_num = (number < 0) ? ft_digit_num_u(number) - 1 : ft_digit_num_u(number);
		if (p->accuracy >= digit_num)
		{
			p->accuracy = p->accuracy - digit_num;
			p->dot = (p->accuracy > 0);
		}
		else
			p->accuracy = 0;
	}
	digit_num = ft_digit_num_u(number);
	if ((p->accuracy + digit_num) < p->width)
		p->width = p->width - (p->accuracy + digit_num);
	else
		p->width = 0;
}
