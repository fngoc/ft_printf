#include "libftprintf.h"

/*
** ft_count_not_N_in_p: подсчет количество N
** в структуре t_parser.
*/

int	ft_count_not_N_in_p(t_parser p)
{
	int count;

	if (p.flags == '-' || p.flags == '0')
		++count;
	if (p.width == '*' || ft_isdigit(p.width))
		++count;
	if (p.dot == '.')
		++count;
	if (ft_isdigit(p.number_after_dot))
		++count;
	if (p.type == 'd' || p.type == 'i' || p.type == 's'
		|| p.type == 'c' || p.type == 'p' || p.type == 'u'
		|| p.type == 'x' || p.type == 'X')
		++count;
	return (count);
}
