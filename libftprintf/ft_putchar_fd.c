#include "libftprintf.h"

/*
** ft_putchar_fd: Выводит символ 'c'
** в указанный файл дескриптор, так же
** подсчитывает количество напечатаных
** символов.
*/

void	ft_putchar_fd(char c, int fd, t_parser *p)
{
	write(fd, &c, 1);
	p->count++;
}
