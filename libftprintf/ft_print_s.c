#include "libftprintf.h"

/*
** ft_print_s: печать типа s.
*/

void	ft_print_s(t_parser *p)
{
	char	*str;

	str = va_arg(p->ap, char *);
	if (!str)
		str = "(null)";
	ft_process_s(p, str);
	if (p->flags == '-')
	{
		ft_putstr_fd_mod_col(str, 1, p, p->accuracy);
		ft_putchar_fd_mod(p->tap, 1, p->width, p);
	}
	else
	{
		ft_putchar_fd_mod(p->tap, 1, p->width, p);
		ft_putstr_fd_mod_col(str, 1, p, p->accuracy);
	}
}
