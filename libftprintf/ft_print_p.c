#include "libftprintf.h"

/*
** ft_print_adress: печатает адрес.
*/

void	ft_print_adress(void *a, t_parser *q, int flag)
{
    unsigned int		p;
    char				s[2 * sizeof(p)];
	int					i;
	unsigned long		j;

	p = (unsigned int)a;
	i = 2 * sizeof(p) - 1;
	j = 0;
	if (!flag)
		ft_putstr_fd_mod("0x7ffe", 1, q);
	else if (flag == 2)
		ft_putstr_fd_mod("7ffe", 1, q);
	else
		ft_putstr_fd_mod("0x1", 1, q);
	while ( i >= 0)
	{
		s[i] = "0123456789abcdef"[p & 0x0F];
		p >>= 4;
		--i;
	}
	while (j < 2 * sizeof(p))
        ft_putchar_fd(s[j++], 1, q);
}

/*
** fr_print_p_two: если есть точка и точность == 0 и ширина > 14.
*/

static void fr_print_p_two(t_parser *p, void *adress)
{
	ft_putchar_fd_mod(' ', 1, p->width - 14, p);
	ft_print_adress(adress, p, 0);
}

/*
** fr_print_p_one: если ширина > точности.
*/

static void fr_print_p_one(t_parser *p, void *adress)
{
	if (p->flags == '-')
	{
		if (p->width > 14)
		{
			ft_print_adress(adress, p, 0);
			ft_putchar_fd_mod(' ', 1, p->width - 14, p);
			return ;
		}
		else
		{
			ft_print_adress(adress, p, 0);
			return ;
		}
	}
	if (p->flags == '0')
	{
		if (p->dot == '.')
		{
			ft_putchar_fd_mod(' ', 1, p->width - 14, p);
			ft_print_adress(adress, p, 0);
			return ;
		}
		if (p->width > 14)
		{
			ft_putstr_fd_mod("0x", 1, p);
			ft_putchar_fd_mod('0', 1, p->width - 14, p);
			ft_print_adress(adress, p, 2);
			return ;
		}
		else
		{
			ft_print_adress(adress, p, 0);
			return ;
		}
	}
	if (p->width > p->accuracy && p->width >= 14 && p->dot == '.')
	{
		ft_putstr_fd_mod("0x", 1, p);
		ft_putchar_fd_mod('0', 1, p->width - 13, p);
		ft_print_adress(adress, p, 2);
		return ;
	}
	if (p->dot == '.')
	{
		if (p->width < 14)
		{
			ft_print_adress(adress, p, 0);
			return ;
		}
		ft_putchar_fd_mod(' ', 1, p->width - 12, p);
		ft_putstr_fd_mod("0x", 1, p);
		ft_putchar_fd_mod('0', 1, p->width - p->accuracy - 2, p);
		ft_print_adress(adress, p, 0);
		return ;
	}
	if (p->width < 14)
	{
		ft_print_adress(adress, p, 0);
		return ;
	}
	ft_puttab(p->width - 14, 1, p);
	ft_print_adress(adress, p, 0);
}

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

	ft_check(p);
	adress = va_arg(p->ap, char *);
	if (!adress)
	{
		fr_print_p_zero(p);
		return ;
	}
	if (p->dot == '.' && p->accuracy == 0 && p->width > 14)
	{
		fr_print_p_two(p, adress);
		return ;
	}
	if (p->dot == '.' && p->accuracy == 0 && p->width == 0)
	{
		ft_print_adress(adress, p, 0);
		return ;
	}
	if (p->dot == '.' && p->accuracy > p->width
		&& p->accuracy > 9)
	{
		ft_print_adress(adress, p, 0);
		return ;
	}
	if (p ->width > p->accuracy)
	{
		fr_print_p_one(p, adress);
		return ;
	}
	if (p->accuracy <= 9 && p->accuracy != 0)
	{
		ft_print_adress(adress, p, 1);
		return ;
	}
	if (p->dot == 'N')
	{
		ft_print_adress(adress, p, 1);
		return ;
	}
	ft_print_adress(adress, p, 0);
}
