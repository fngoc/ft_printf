#include "libftprintf.h"

/*
** ft_isdigit: возвращает ненулевое значение,
** если аргумент c является цифрой от 0 до 9,
** в противном случае возвращается 0.
*/

int	ft_isdigit(int c)
{
	return (((c >= '0') && (c <= '9')) ? 1 : 0);
}
