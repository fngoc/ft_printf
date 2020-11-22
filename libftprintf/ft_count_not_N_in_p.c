#include "libftprintf.h"

/*
** ft_count_not_N_in_p: подсчет количество N
** в структуре t_parser.
*/

int	ft_count_not_N_in_p(t_parser p)
{
	int count_flags;

	count_flags = 0;
	if (p.flags == '-' || p.flags == '0')
		++count_flags;
	if (p.width == '*' || p.width != 78)
		++count_flags;
	if (p.dot == '.')
		++count_flags;
	if (p.number_after_dot != 78)
		++count_flags;
	if (p.type == 'd' || p.type == 'i' || p.type == 's'
		|| p.type == 'c' || p.type == 'p' || p.type == 'u'
		|| p.type == 'x' || p.type == 'X')
		++count_flags;
	return (count_flags);
}
