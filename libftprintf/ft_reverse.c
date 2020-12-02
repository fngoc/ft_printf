#include "libftprintf.h"

/*
** ft_reverse: разворачивает строку.
*/

void ft_reverse(char *s)
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
