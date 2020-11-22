#include "libftprintf.h"

/*
** ft_print_unsigned_int_mod: выводит unsigned_int.
*/

void	ft_print_unsigned_int_mod(int a, int coll_tabs)
{
	int tmp;

	tmp = ft_digit_num(a);
	if (a >= 0)
	{
		ft_puttab(coll_tabs - tmp, 1);
		ft_putnbr_fd(a, 1);
	}
	else
	{
//		printf("I AM HERE\n");
		a = a + 1;
		ft_putnbr_fd_mod(4294967295 + a, 1, coll_tabs);
	}
}
