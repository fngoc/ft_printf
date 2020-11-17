#include "libftprintf.h"

/*
** ft_print_unsigned_int: выводит unsigned_int.
*/

void	ft_print_unsigned_int(int a)
{
	if (a >= 0)
		ft_putnbr_fd(a, 1);
	else
	{
		a = a + 1;
		ft_putnbr_fd(4294967295 + a, 1);
	}
}
