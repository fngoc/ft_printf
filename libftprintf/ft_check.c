#include "libftprintf.h"

/*
** ft_check: проверка
** на наличие '*' в парсере для
** width и accuracy.
*/

void ft_check(t_parser *p)
{
	if (p->width == '*')
	{
		p->width = va_arg(p->ap, int);
		if (p->width < 0)
		{
			p->flags = '-';
			p->tap = ' ';
			p->width = p->width * (-1);
		}
	}
	if (p->accuracy == '*')
	{
		p->accuracy = va_arg(p->ap, int);
		if (p->accuracy < 0)
		{
			p->check_for_str = 'Y';
			p->dot = 'N';
			p->accuracy = 0;
		}
	}
}
