#include "libftprintf.h"

/*
** fr_print_s_two_utils: для нормы.
*/

static void	fr_print_s_two_utils(t_parser *p, char *str)
{
	if (p->width > ft_strlen(str) && p->dot == '.'
		&& p->accuracy > ft_strlen(str))
	{
		ft_putstr_fd_mod_col(str, 1, p, p->accuracy);
		ft_puttab(p->width - ft_strlen(str), 1, p);
		return ;
	}
	if (p->width > ft_strlen(str) && p->dot == '.')
	{
		ft_putstr_fd_mod_col(str, 1, p, p->accuracy);
		ft_puttab(p->width - p->accuracy, 1, p);
		return ;
	}
	if (p->width > ft_strlen(str))
	{
		ft_putstr_fd_mod(str, 1, p);
		ft_puttab(p->width - ft_strlen(str), 1, p);
		return ;
	}
	ft_putstr_fd_mod_col(str, 1, p, p->accuracy);
	ft_puttab(p->width - p->accuracy, 1, p);
	return ;
}

/*
** fr_print_s_two: если точность < ширины.
*/

static void	fr_print_s_two(t_parser *p, char *str)
{
	if (p->flags == '-')
	{
		fr_print_s_two_utils(p, str);
		return ;
	}
	if (p->flags == '0')
	{
		ft_putchar_fd_mod('0', 1, p->width - p->accuracy, p);
		ft_putstr_fd_mod_col(str, 1, p, p->accuracy);
		return ;
	}
	if (p->width > ft_strlen(str) && p->accuracy > ft_strlen(str))
	{
		ft_puttab(p->width - ft_strlen(str), 1, p);
		ft_putstr_fd_mod(str, 1, p);
		return ;
	}
	ft_puttab(p->width - p->accuracy, 1, p);
	ft_putstr_fd_mod_col(str, 1, p, p->accuracy);
}

/*
** fr_print_s_one: если точность > ширины.
*/

static void	fr_print_s_one(t_parser *p, char *str)
{
	if (ft_strlen(str) == 0)
	{
		ft_putchar_fd_mod(' ', 1, p->width, p);
		ft_putstr_fd_mod_col(str, 1, p, p->accuracy);
		return ;
	}
	if ((p->flags == '-' || p->flags == '0')
		&& (ft_strlen(str) < p->accuracy))
	{
		if (p->flags == '-' && p->width > ft_strlen(str)
			&& p->dot == '.' && p->accuracy > ft_strlen(str))
		{
			ft_putstr_fd_mod(str, 1, p);
			ft_puttab(p->width - ft_strlen(str), 1, p);
			return ;
		}
		ft_putstr_fd_mod(str, 1, p);
	}
	else
		ft_putstr_fd_mod_col(str, 1, p, p->accuracy);
}

/*
** fr_print_s_zero: если точность == ширины.
*/

static void	fr_print_s_zero(t_parser *p, char *str)
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
		ft_putstr_fd_mod_col(str, 1, p, ft_strlen(str) - p->width + 1);
		return ;
	}
}

void		ft_print_s_utils_one(t_parser *p, char *str)
{
	if (p->accuracy == 0)
	{
		ft_print_s_utils_three(p, str);
		return ;
	}
	if (p->width > p->accuracy)
	{
		fr_print_s_two(p, str);
		return ;
	}
	if (p->accuracy > p->width)
	{
		fr_print_s_one(p, str);
		return ;
	}
	if (p->width == p->accuracy)
	{
		fr_print_s_zero(p, str);
		return ;
	}
}
