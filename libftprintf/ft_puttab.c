#include "libftprintf.h"

/*
** ft_puttab: Выводит символ ' '
** в указанный файл дескриптор coll раз.
*/

void	ft_puttab(int col, int fd)
{
	char tab;

	tab = ' ';
	while (col != 0)
	{
		write(fd, &tab, 1);
		--col;
	}
}
