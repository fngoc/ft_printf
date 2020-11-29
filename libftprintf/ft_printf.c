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
	if (!format)
		return (0);
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
