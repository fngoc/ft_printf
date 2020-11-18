#include "libftprintf.h"

/*
** ft_putstr_fd_print_int_str: Выводит строку в
** указанный файл дескриптор, указаное количество символов.
*/

void	ft_putstr_fd_print_int_str(char *s, int fd, int f)
{
	int len;
	int i;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len && f-- != 0)
		write(fd, &s[i++], 1);
}
