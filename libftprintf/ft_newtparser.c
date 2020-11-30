#include "libftprintf.h"

/*
** ft_newtparser: устанавливает переменной
** 'p' с типом t_parser, значения по умолчанию.
*/

void ft_newtparser(t_parser *p)
{
	p->flags = 'N';
	p->width = 0;
	p->dot = 'N';
	p->accuracy = 0;
	p->type = 'N';
	p->tap = ' ';
}
