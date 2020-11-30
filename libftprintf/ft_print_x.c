#include "libftprintf.h"

/*
** ft_reverse: разворот строки.
*/

void	ft_reverse(char s[])
{
	int c;
	int i;
	int j;

	i = 0;
	j = (int)ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
  }
}

/*
** ft_print_hex_little: преобразование n в строку s,
** представляющую число по основанию 16, буквы
** в нижнем регистре.
*/

void	ft_print_hex_little(signed long long int n, t_parser *p)
{
	int i;
	signed long long int sign;
	char digits[] = "0123456789abcdef";
	char s[25];

	sign = n;
	i = 0;
	s[i++] = digits[n % 16];
	while (n /= 16)
		s[i++] = digits[n % 16];
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_reverse(s);
	ft_putstr_fd_mod(s, 1, p);
}

/*
** ft_print_x: выводит в 16 сичтеме счисления.
*/

void ft_print_x(t_parser *p)
{
	int number;

	ft_check(p);
	number = va_arg(p->ap, int);
	ft_print_hex_little(number, p);
}
