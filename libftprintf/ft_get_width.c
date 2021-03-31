#include "libftprintf.h"

/*
** ft_get_width: берет значение width.
*/

void	ft_get_width(t_parser *p)
{
	p->width = va_arg(p->ap, int);
	if (p->width < 0)
	{
		p->flags = '-';
		p->tap = ' ';
		p->width = p->width * (-1);
	}
}
