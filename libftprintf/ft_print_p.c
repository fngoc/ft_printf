#include "libftprintf.h"

/*
** fr_print_p_zero: если адрес == NULL или 0.
*/

static void	fr_print_p_zero(t_parser *p)
{
	if (p->dot == 'N')
	{
		if (p->width < 3)
			ft_putstr_fd_mod("0x0", 1, p);
		else if (p->width > 0 && p->flags != '-')
		{
			ft_putchar_fd_mod(' ', 1, p->width - 3, p);
			ft_putstr_fd_mod("0x0", 1, p);
		}
		else if (p->width > 0 && p->flags == '-')
		{
			ft_putstr_fd_mod("0x0", 1, p);
			ft_putchar_fd_mod(' ', 1, p->width - 3, p);
		}
		else
			ft_putstr_fd_mod("0x0", 1, p);
	}
	else if (p->dot == '.' && p->width > 0)
	{
		if (p->width > 2)
			ft_putchar_fd_mod(' ', 1, p->width - 2, p);
		ft_putstr_fd_mod("0x", 1, p);
	}
	else
		ft_putstr_fd_mod("0x0", 1, p);
}

/*
** ft_print_address_flag_minus: если флаг '-'.
*/

static void	ft_print_address_flag_minus(char *str, t_parser *p)
{
	if (p->width > 0 && p->width >= 14)
	{
		ft_putstr_fd_mod(str, 1, p);
		ft_putchar_fd_mod(' ', 1, p->width - ft_strlen(str), p);
		return ;
	}
	ft_putstr_fd_mod(str, 1, p);
}

/*
** ft_print_address_noflag: если фагов нет.
*/

static void	ft_print_address_noflag(char *str, t_parser *p)
{
	if (p->width > 0 && p->width >= 14)
	{
		ft_putchar_fd_mod(' ', 1, p->width - ft_strlen(str), p);
		ft_putstr_fd_mod(str, 1, p);
		return ;
	}
	ft_putstr_fd_mod(str, 1, p);
}

/*
** ft_print_p: выводит адрес.
*/

void		ft_print_p(t_parser *p)
{
	void *address;
	char buf[20];

	ft_check(p);
	address = va_arg(p->ap, char *);
	if (!address)
	{
		fr_print_p_zero(p);
		return ;
	}
	ft_make_address(address, buf);
	if (p->flags == '-')
		ft_print_address_flag_minus(buf, p);
	else
		ft_print_address_noflag(buf, p);
}
