#include "libftprintf.h"

/*
** ft_putstr_fd_mod: Выводит строку в
** указанный файл дескриптор.
*/

void	ft_putstr_fd_mod(char *s, int fd, int coll_tabs)
{
	int len;
	int i;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	len = ft_strlen(s);
	ft_puttab(coll_tabs - len, 1);
	while (i < len)
		write(fd, &s[i++], 1);
}
