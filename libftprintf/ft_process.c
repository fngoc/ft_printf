#include "libftprintf.h"

/*
** ft_process: установка значений в ширину и точность.
*/

void	ft_process(t_parser *p, int number)
{
	int digit_num;

	if (p->dot == '.')
	{
		p->tap = ' ';
		digit_num = (number < 0) ? ft_digit_num(number) - 1 : ft_digit_num(number);
		if (p->accuracy >= digit_num)
		{
			p->accuracy = p->accuracy - digit_num;
			p->dot = (p->accuracy > 0);
		}
		else
			p->accuracy = 0;
	}
	digit_num = ft_digit_num(number);
	if ((p->accuracy + digit_num) < p->width)
		p->width = p->width - (p->accuracy + digit_num);
	else
		p->width = 0;
}
