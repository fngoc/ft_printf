#include "libftprintf.h"

/*
** ft_print_parser: печать парсера
** в зависимости от типа.
*/

int	ft_print_parser(t_parser *p)
{
	if (p->type == 'd' || p->type == 'i')
		ft_print_d_or_i(p);
	if (p->type == 'c')
		ft_print_c(p);
	if (p->type == 's')
		ft_print_s(p);
	return (0);
}
