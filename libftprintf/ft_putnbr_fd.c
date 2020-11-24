#include "libftprintf.h"

/*
** ft_putnbr_fd: Выводит целое число 'n'
** в указанный файл дескриптор.
*/

static void	print_symbole(long int n, int fd, t_parser *p)
{
	if (n > 9)
		print_symbole(n / 10, fd, p);
	ft_putchar_fd((n % 10 + '0'), fd, p);
}

void		ft_putnbr_fd(int n, int fd, t_parser *p)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd, p);
		print_symbole((long int)n * (-1), fd, p);
	}
	else
		print_symbole((long int)n, fd, p);
}
