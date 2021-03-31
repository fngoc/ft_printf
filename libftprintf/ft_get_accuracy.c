#include "libftprintf.h"

/*
** ft_get_accuracy: берет значение accuracy.
*/

void	ft_get_accuracy(t_parser *p)
{
	p->accuracy = va_arg(p->ap, int);
	if (p->accuracy < 0)
	{
		p->dot = 'N';
		p->accuracy = 0;
	}
}
