#include "libftprintf.h" /* Моя библиотека */
#include <stdio.h> /* Для printf */

int		main(void)
{
	char *a = "123vxcz";
	printf("Adress printf: %p\n", &a);
	ft_printf("Adress ft_printf: %p\n", &a);
	printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
	ft_printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
	printf("%u\n", -11);
	ft_printf("%u\n", -11);
	return (0);
}
