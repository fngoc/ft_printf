#include "libftprintf.h"
#include "stdio.h"

/*
** ft_printf: читает и выводит свои аргументы.
*/

t_parser		ft_printf(const char *format, ...)
{
	va_list ap;
	t_parser p;
	char *str;
	int count;
	int count_not_N;

	va_start(ap, format);
	while (*format)
	{
		if (*format++ != '%')
		{
			write(1, format, 1);
			++count;
		}
		else
		{
			if (*format == '%')
			{
				write(1, format, 1);
				++count;
			}
			else
			{
				p = ft_parser((char *)format);
				count_not_N = ft_count_not_N_in_p(p);
				format += count_not_N;
//				ft_print_parser(p);
			}
		}
	}
	va_end(ap);
	return (p);
}


//			if (*format == 'd' || *format == 'i')
//				ft_putnbr_fd(va_arg(ap, int), 1);
//			if (*format == 's')
//				ft_putstr_fd(va_arg(ap, char *), 1);
//			if (*format == 'c')
//				ft_putchar_fd(va_arg(ap, int), 1);
//			if (*format == '%')
//				ft_putchar_fd('%', 1);
//			if (*format == 'p')
//				ft_print_adress(va_arg(ap, void *));
//			if (*format == 'u')
//				ft_print_unsigned_int(va_arg(ap, int));
//			if (*format == 'x')
//				ft_print_hex_little(va_arg(ap, int));
//			if (*format == 'X')
//				ft_print_hex_big(va_arg(ap, int));
//			if (*format++ == '.' && (str = (char *) format))
//			{
//				if (ft_isdigit(*str) && (tmp = ft_atoi(format)))
//					while (ft_isdigit(*format))
//						format += 1;
//				if (*format == 's')
//					ft_putstr_fd_print_int_str(va_arg(ap, char *), 1, tmp);
//			}
