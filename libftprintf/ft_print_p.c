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
		ft_putstr_fd_mod("0x1", 1, q);
	else
		ft_putstr_fd_mod("01", 1, q);
	while ( i >= 0)
	{
		s[i] = "0123456789abcdef"[p & 0x0F];
		p >>= 4;
		--i;
	}
	while (j < 2 * sizeof(p))
    {
        ft_putchar_fd(s[j], 1, q);
		++j;
    }
}

/*
** fr_print_p_two:
*/

static void fr_print_p_two(t_parser *p, void *adress)
{
	if (p ->width < p->number_after_dot)
	{
		ft_putstr_fd_mod("0x", 1, p);
		ft_putchar_fd_mod('0', 1, p->number_after_dot - 10, p);
		ft_print_adress(adress, p, 1);
	}
}

/*
** fr_print_p_one:
*/

static void fr_print_p_one(t_parser *p, void *adress)
{
	if (p->flags == '-')
	{
		if (p->width > 11)
		{
			ft_print_adress(adress, p, 0);
			ft_putchar_fd_mod(' ', 1, p->width - 11, p);
			return ;
		}
		else
		{
			ft_print_adress(adress, p, 0);
			return ;
		}
	}
	if (p->width < 11)
	{
		ft_print_adress(adress, p, 0);
		return ;
	}
	ft_puttab(p->width - 11, 1, p);
	ft_print_adress(adress, p, 0);
}

/*
** fr_print_s_zero:
*/

static void fr_print_p_zero(t_parser *p)
{
	if (p->chek == 'Y')
	{
		ft_putstr_fd_mod("0x0", 1, p);
		return ;
	}
	if (p->width > p->number_after_dot && p->number_after_dot == 0)
	{
		ft_putchar_fd_mod(' ', 1, p->width - 3, p);
		ft_putstr_fd_mod("0x0", 1, p);
		return ;
	}
	if (p->dot == '.' && p->number_after_dot == 0 && p->width == 0)
	{
		ft_putstr_fd_mod("0x", 1, p);
		return ;
	}
	if (p ->width > p->number_after_dot && p->number_after_dot != 0)
	{
		ft_putstr_fd_mod("0x0", 1, p);
		ft_putchar_fd_mod('0', 1, p->width - 3, p);
		return ;
	}
	if (p ->width < p->number_after_dot)
	{
		ft_putstr_fd_mod("0x0", 1, p);
		ft_putchar_fd_mod('0', 1, p->number_after_dot - 1, p);
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

	ft_chek_width_and_numberafterdot(p);
	adress = va_arg(p->ap, char *);
	if (!adress)
	{
		fr_print_p_zero(p);
		return ;
	}
	if (p->dot == '.' && p->number_after_dot > p->width
		&& p->number_after_dot > 9)
	{
		fr_print_p_two(p, adress);
		return ;
	}
	if (p ->width > p->number_after_dot)
	{
		fr_print_p_one(p, adress);
		return ;
	}
	ft_print_adress(adress, p, 0);
}
