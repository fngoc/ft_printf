#include "libftprintf.h"

/*
** ft_printf: читает и выводит свои аргументы.
*/

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
		else
		{
			++format;
			if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			if (*format == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			if (*format == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			if (*format == '%')
				ft_putchar_fd('%', 1);
			if (*format == 'p')
				ft_print_adress(va_arg(ap, void *));
			if (*format == 'u')
				ft_print_unsigned_int(va_arg(ap, int));
			if (*format == 'x')
				ft_print_hex_little(va_arg(ap, int));
			if (*format == 'X')
				ft_print_hex_big(va_arg(ap, int));
		}
		format++;
	}
	va_end(ap);
	return (0);
}
