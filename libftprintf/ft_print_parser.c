#include "libftprintf.h"

/*
** ft_print_parser_chek_two: проверяет и печатает
** если подал 2 флага.
*/

void	ft_print_parser_chek_two(t_parser p)
{
		if (p.type == 'd' || p.type == 'i')
			two_arg_d(p);
		else if (p.type == 's')
			two_arg_s(p);
		else if (p.type == 'c')
			two_arg_c(p);
		else if (p.type == '%')
			ft_putchar_fd('%', 1);
		else if (p.type == 'p')
			two_arg_p(p);
		else if (p.type == 'u')
			two_arg_u(p);
		else if (p.type == 'x')
			ft_print_hex_little(va_arg(ap, int));
		else if (p.type == 'X')
			ft_print_hex_big(va_arg(ap, int));
}

/*
** ft_print_parser_chek_one: проверяет и печатает
** если подал 1 флаг.
*/

void	ft_print_parser_chek_one(t_parser p)
{
		if (p.type == 'd' || p.type == 'i')
			ft_putnbr_fd(va_arg(ap, int), 1);
		else if (p.type == 's')
			ft_putstr_fd(va_arg(ap, char *), 1);
		else if (p.type == 'c')
			ft_putchar_fd(va_arg(ap, int), 1);
		else if (p.type == '%')
			ft_putchar_fd('%', 1);
		else if (p.type == 'p')
			ft_print_adress(va_arg(ap, void *));
		else if (p.type == 'u')
			ft_print_unsigned_int(va_arg(ap, int));
		else if (p.type == 'x')
			ft_print_hex_little(va_arg(ap, int));
		else if (p.type == 'X')
			ft_print_hex_big(va_arg(ap, int));
}

/*
** ft_print_parser: печать парсера.
*/

int	ft_print_parser(t_parser p)
{
//	printf("%d\n", ft_count_not_N_in_p(p));
	if (ft_count_not_N_in_p(p) == 1)
		ft_print_parser_chek_one(p);
	else if (ft_count_not_N_in_p(p) == 2)
		ft_print_parser_chek_two(p);

	return (0);
}
