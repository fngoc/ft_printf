#include "libftprintf.h"

/*
** ft_putchar_fd_mod: Выводит символ 'c'
** в указанный файл дескриптор.
*/

void	ft_putchar_fd_mod(char c, int fd, int coll_tabs)
{
	ft_puttab(coll_tabs - 1, 1);
	write(fd, &c, 1);
}
