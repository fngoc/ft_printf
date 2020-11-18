#include "libftprintf.h"

/*
** dec_in_bin: переводит число из десятичной
** в двоичную систему счисления.
*/

int	dec_in_bin(int num)
{
	int	bin = 0;
	int	k = 1;

	while (num)
	{
		bin += (num % 2) * k;
		k *= 10;
		num /= 2;
	}
	return bin;
}
