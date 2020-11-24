#include "libftprintf.h"

/*
** ft_strlen: возвращает количество символов в строке.
*/

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}
