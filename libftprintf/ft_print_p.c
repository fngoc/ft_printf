#include "libftprintf.h"

/*
** fr_print_s_zero: если адрес == NULL или 0.
*/

static void fr_print_p_zero(t_parser *p)
{
	if (p->dot == 'N')
	{
		ft_putstr_fd_mod("0x0", 1, p);
		return ;
	}
	if (p->width > p->accuracy && p->accuracy == 0)
	{
		ft_putchar_fd_mod(' ', 1, p->width - 3, p);
		ft_putstr_fd_mod("0x0", 1, p);
		return ;
	}
	if (p->dot == '.' && p->accuracy == 0 && p->width == 0)
	{
		ft_putstr_fd_mod("0x", 1, p);
		return ;
	}
	if (p ->width > p->accuracy && p->accuracy != 0)
	{
		ft_putstr_fd_mod("0x0", 1, p);
		ft_putchar_fd_mod('0', 1, p->width - 3, p);
		return ;
	}
	if (p ->width < p->accuracy)
	{
		ft_putstr_fd_mod("0x0", 1, p);
		ft_putchar_fd_mod('0', 1, p->accuracy - 1, p);
		return ;
	}
	ft_putstr_fd_mod("0x0", 1, p);
}

/*
** ft_print_p: выводит адрес.
*/

void	ft_print_p(t_parser *p)
{
	void *adress;
	char str[17];

	ft_check(p);
	adress = va_arg(p->ap, char *);
	if (!adress)
	{
		fr_print_p_zero(p);
		return ;
	}
	ft_print_addres(adress, str);
	ft_putstr_fd_mod(str, 1, p);
}
