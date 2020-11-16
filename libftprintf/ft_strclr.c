#include "libftprintf.h"

/*
** ft_strclr: очищает строку.
*/

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}
