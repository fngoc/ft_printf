#include "libftprintf.h"

/*
** ft_putchar_fd_mod: Выводит символ 'c'
** в указанный файл дескриптор, coll раз.
*/

void	ft_putchar_fd_mod(char c, int fd, int coll, t_parser *p)
{
	while (coll-- != 0)
		ft_putchar_fd(c, fd, p);
}
