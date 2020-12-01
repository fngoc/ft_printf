#include "libftprintf.h"

/*
** ft_tolower: переводит из 'A' в 'a'.
*/

//static char	ft_tolower(char c)
//{
//	if (c >= 'A' && c <= 'Z')
//		return (c - 32);
//	return (c);
//}

/*
** ft_reverse: разворачивает строку.
*/

static void ft_reverse(char *s)
{
	int c;
	int i;
	int j;

	i = 0;
	j = ft_strlen(s) - 1;
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
** dec_to_hex: из 10 в 16 систему.
*/

static void dec_to_hex(char *str, long l)
{
	int i;
	int ost;

	i = 0;
	while (l > 0)
	{
		ost = l % 16;
		if (ost > 9)
			str[i] = 'a' + ost - 10;
		else
			str[i] = '0' + ost;
		l = l / 16;
		++i;
	}
}

/*
** ft_print_addres: выводит адресс переменной.
*/

void ft_print_addres(char *adres, char *result)
{
	long int addres_long;

	ft_memcpy(&addres_long, &adres, sizeof(void*));
	dec_to_hex(result, addres_long);
	ft_reverse(result);
}
