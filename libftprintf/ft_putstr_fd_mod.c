#include "libftprintf.h"

/*
** ft_putstr_fd: Выводит строку в
** указанный файл дескриптор.
*/

void	ft_putstr_fd_mod(char *s, int fd, t_parser *p)
{
	int len;
	int i;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
		ft_putchar_fd(s[i++], fd, p);
}
