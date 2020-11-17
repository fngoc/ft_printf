#include "libftprintf.h"

/*
** ft_print_adress: выводит адрес.
*/

void	ft_print_adress(void *a)
{
    unsigned int		p;
    char				s[2 * sizeof(p)];
	int					i;
	unsigned long		j;

	p = (unsigned int)a;
	i = 2 * sizeof(p) - 1;
	j = 0;
	ft_putstr_fd("0x7ffe", 1);
	while ( i >= 0)
	{
		s[i] = "0123456789abcdef"[p & 0x0F];
		p >>= 4;
		--i;
	}
	while (j < 2 * sizeof(p))
    {
        ft_putchar_fd(s[j], 1);
		++j;
    }
}
