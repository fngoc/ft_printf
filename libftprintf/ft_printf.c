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
//				printf("Parser:\n%c\n%d\n%d\n%c\n", p.flags, p.width, p.accuracy, p.type);
			}
		}
		++format;
	}
	va_end(p.ap);
	return (p.count);
}

//			if (*format == 'p')
//				ft_print_adress(va_arg(ap, void *));
//			if (*format == 'u')
//				ft_print_unsigned_int(va_arg(ap, int));
//			if (*format == 'x')
//				ft_print_hex_little(va_arg(ap, int));
//			if (*format == 'X')
//				ft_print_hex_big(va_arg(ap, int));
