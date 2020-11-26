#include "libftprintf.h"

/*
** ft_chek_width_and_numberafterdot: проверка
** на наличие '*' в парсере для
** width и number_after_dot.
*/

void ft_chek_width_and_numberafterdot(t_parser *p)
{
	if (p->width == '*')
	{
		p->width = va_arg(p->ap, int);
		if (p->width < 0)
		{
			p->flags = '-';
			p->width = p->width * (-1);
		}
	}
	if (p->number_after_dot == '*')
	{
		p->number_after_dot = va_arg(p->ap, int);
		if (p->number_after_dot < 0)
		{
			p->chek = 'Y';
			p->number_after_dot = 0;
		}
	}
	//printf("Parser:\n%c\n%d\n%d\n%c\n", p->flags, p->width, p->number_after_dot, p->type);
}
