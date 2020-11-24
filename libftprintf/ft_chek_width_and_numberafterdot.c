#include "libftprintf.h"

/*
** ft_chek_width_and_numberafterdot: проверка
** на наличие '*' в парсере для
** width и number_after_dot.
*/

void ft_chek_width_and_numberafterdot(t_parser *p)
{
	if (p->width == '*')
		p->width = va_arg(p->ap, int);
	if (p->number_after_dot == '*')
		p->number_after_dot = va_arg(p->ap, int);
}
