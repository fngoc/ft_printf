#include "libftprintf.h"

/*
** ft_print_s: печать типа s.
*/

void	ft_print_s(t_parser *p)
{
	char	*str;

	ft_check(p);
	str = va_arg(p->ap, char *);
	if (!str)
		str = "(null)";
	if (p->check_for_str == 'Y')
		ft_putstr_fd_mod(str, 1, p);
	if (p->width == 0 && p->accuracy == 0 && p->dot == '.')
		return ;
	if (p->width != 0 && p->accuracy == 0 && p->dot == '.')
	{
		ft_print_s_utils_two(p, str);
		return ;
	}
	if ((p->accuracy == 0) || (p->width > p->accuracy) ||
		(p->accuracy > p->width) || (p->width == p->accuracy))
	{
		ft_print_s_utils_one(p, str);
		return ;
	}
	ft_putstr_fd_mod(str, 1, p);
}
