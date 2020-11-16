
#include "libftprintf.h" /* Моя библиотека */
#include <stdio.h> /* Для printf */

/*
** ft_printf: читает и выводит свои аргументы.
*/

int	ft_printf(const char *format, ...)
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
			if (*format == 'u')
				ft_putnbr_fd((unsigned int)va_arg(ap, unsigned int), 1);
			if (*format == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			if (*format == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			if (*format == '%')
				ft_putchar_fd('%', 1);
		}
		format++;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
	ft_printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
	printf("%u\n", -1);
	ft_printf("%u\n", -1);
//	int a = 10;
//	int *b = &a;
//	printf("%p\n", b);
	return (0);
}
