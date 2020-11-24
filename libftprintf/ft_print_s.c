#include "libftprintf.h"

/*
** fr_print_s_three: если у нас нет точности.
*/

static void fr_print_s_three(t_parser *p, char *str)
{
	if ((p->flags == '-' || p->flags == '0') && (ft_strlen(str) > p->width))
	{
		ft_putstr_fd_mod(str, 1, p);
		return ;
	}
	if (p->flags == '-' && p->width > ft_strlen(str))
	{
		ft_putstr_fd_mod(str, 1, p);
		ft_puttab(p->width - ft_strlen(str), 1, p);
		return ;
	}
	if (p->flags == '0' && p->width > ft_strlen(str))
	{
		ft_putchar_fd_mod('0', 1, p->width - ft_strlen(str), p);
		ft_putstr_fd_mod(str, 1, p);
		return ;
	}
	if (p->width > ft_strlen(str))
	{
		ft_puttab(p->width - ft_strlen(str), 1, p);
		ft_putstr_fd_mod(str, 1, p);
		return ;
	}
	ft_putstr_fd_mod(str, 1, p);
}

/*
** fr_print_s_two: если точность < ширины.
*/

static void fr_print_s_two(t_parser *p, char *str)
{
	if (p->flags == '-')
	{
		ft_putstr_fd_mod_col(str, 1, p, p->number_after_dot);
		ft_puttab(p->width - p->number_after_dot, 1, p);
		return ;
	}
	if (p->flags == '0')
	{
		ft_putchar_fd_mod('0', 1, p->width - p->number_after_dot, p);
		ft_putstr_fd_mod_col(str, 1, p, p->number_after_dot);
		return ;
	}
	ft_puttab(p->width - p->number_after_dot, 1, p);
	ft_putstr_fd_mod_col(str, 1, p, p->number_after_dot);
}

/*
** fr_print_s_one: если точность > ширины.
*/

static void fr_print_s_one(t_parser *p, char *str)
{
	if ((p->flags == '-' || p->flags == '0')
		&& (ft_strlen(str) < p->number_after_dot))
		ft_putstr_fd_mod(str, 1, p);
	else
		ft_putstr_fd_mod_col(str, 1, p, p->number_after_dot);
}

/*
** fr_print_s_zero: если точность == ширины.
*/

static void fr_print_s_zero(t_parser *p, char *str)
{
	if (p->flags == '-' && (ft_strlen(str) < p->width))
	{
		ft_putstr_fd_mod(str, 1, p);
		ft_puttab(p->width - ft_strlen(str), 1, p);
		return ;
	}
	if (p->flags == '0' && (ft_strlen(str) < p->width))
	{
		ft_putchar_fd_mod('0', 1, p->width - ft_strlen(str), p);
		ft_putstr_fd_mod(str, 1, p);
		return ;
	}
	if (ft_strlen(str) < p->width)
	{
		ft_puttab(p->width - ft_strlen(str), 1, p);
		ft_putstr_fd_mod(str, 1, p);
		return ;
	}
	if (ft_strlen(str) > p->width)
	{
		ft_putstr_fd_mod_col(str, 1, p, ft_strlen(str) - p->width);
		return ;
	}
}

/*
** ft_print_s: печать типа s.
*/

void	ft_print_s(t_parser *p)
{
	char	*str;

	ft_chek_width_and_numberafterdot(p);
	str = va_arg(p->ap, char *);
	if (p->number_after_dot == 0)
	{
		fr_print_s_three(p, str);
		return ;
	}
	if (p->width > p->number_after_dot)
	{
		fr_print_s_two(p, str);
		return ;
	}
	if (p->number_after_dot > p->width)
	{
		fr_print_s_one(p, str);
		return ;
	}
	if (p->width == p->number_after_dot)
	{
		fr_print_s_zero(p, str);
		return ;
	}
	ft_putstr_fd_mod(str, 1, p);
}
