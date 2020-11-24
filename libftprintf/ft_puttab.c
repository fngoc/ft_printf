#include "libftprintf.h"

/*
** ft_puttab: Выводит символ ' '
** в указанный файл дескриптор coll раз.
*/

void	ft_puttab(int col, int fd, t_parser *p)
{
	char tab;

	tab = ' ';
	while (col-- != 0)
		ft_putchar_fd(tab, fd, p);
}
