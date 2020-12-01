#include "libftprintf.h"

/*
** fr_print_s_three_utils: функция для нормы.
*/

static void	fr_print_s_three_utils(t_parser *p, char *str)
{
	ft_putchar_fd_mod('0', 1, p->width - ft_strlen(str), p);
	ft_putstr_fd_mod(str, 1, p);
}

/*
** ft_print_s_utils_three: если у нас нет точности.
*/

void		ft_print_s_utils_three(t_parser *p, char *str)
{
	if (p->check_for_str == 'Y')
		return ;
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
		fr_print_s_three_utils(p, str);
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
** ft_print_s_utils_two: если ширина != 0 и
** точность == 0 и есть точка.
*/

void		ft_print_s_utils_two(t_parser *p, char *str)
{
	if (p->flags == '-')
	{
		ft_puttab(p->width, 1, p);
		return ;
	}
	if (p->width > ft_strlen(str))
	{
		if (p->width > ft_strlen(str) && p->accuracy == 0)
		{
			ft_putchar_fd_mod(' ', 1, p->width, p);
			return ;
		}
		ft_putchar_fd_mod(' ', 1, p->width - ft_strlen(str), p);
		ft_putstr_fd_mod(str, 1, p);
		return ;
	}
	ft_puttab(p->width, 1, p);
}
