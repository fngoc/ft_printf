#include "libftprintf.h"

/*
** ft_chek_width_and_accuracy: проверка
** на наличие '*' в парсере для
** width и accuracy.
*/

void ft_chek_width_and_accuracy(t_parser *p)
{
	if (p->width == '*')
	{
		p->width = va_arg(p->ap, int);
//		if (p->width < 0)
//		{
//			p->flags = '-';
//			p->width = p->width * (-1);
//		}
	}
	if (p->accuracy == '*')
	{
		p->accuracy = va_arg(p->ap, int);
//		if (p->accuracy < 0)
//		{
//			p->chek = 'Y';
//			p->accuracy = 0;
//		}
	}
	//printf("Parser:\n%c\n%d\n%d\n%c\n", p->flags, p->width, p->accuracy, p->type);
}
