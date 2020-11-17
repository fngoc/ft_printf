#include "libftprintf.h"

/*
** ft_print_hex_big: преобразование n в строку s,
** представляющую число по основанию 16, буквы
** в верхнем регистре.
*/

void	ft_print_hex_big(int n)
{
	int i;
	int sign;
	char digits[] = "0123456789ABCDEF";
	char s[25];

	sign = n;
	i = 0;
	s[i++] = digits[n % 16];
	while (n /= 16)
	{
		s[i++] = digits[n % 16];
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_reverse(s);
	ft_putstr_fd(s, 1);
}
