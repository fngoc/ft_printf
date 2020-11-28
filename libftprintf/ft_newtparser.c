#include "libftprintf.h"

/*
** ft_newtparser: устанавливает переменной
** 'p' с типом t_parser, значения по умолчанию.
*/

void ft_newtparser(t_parser *p)
{
	p->flags = 'N';
	p->width = -1;
	p->dot = 'N';
	p->accuracy = -1;
	p->type = 'N';
}
