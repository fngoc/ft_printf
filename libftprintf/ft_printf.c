#include "libftprintf.h"

/*
** ft_printf: читает и выводит свои аргументы
** возвращает кол-во напечатаных символов.
*/

int	ft_printf(const char *format, ...)
{
	t_parser	p;

	p.count = 0;
	va_start(p.ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar_fd(*format, 1, &p);
		else
		{
			if (*++format == '%')
				ft_putchar_fd(*format, 1, &p);
			else
			{
				ft_parser((char **)&format, &p);
				ft_print_parser(&p);
			}
		}
		++format;
	}
	va_end(p.ap);
	return (p.count);
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
