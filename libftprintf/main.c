#include "libftprintf.h" /* Моя библиотека */

int		main(void)
{
	/* Тестирование */
//	printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
//	ft_printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
//	ft_printf("%d\n%s\n%c\n%%\n%s\n%d\n", 21, "lol", 't', "kek", 17);
	printf("%4....1s\n", "0");
	int len = ft_printf("%4....1s\n", "0");
	printf("len: %d\n", len);
	/* Сделать */
//	ft_printf("%-4.9d\n", 10);
//	ft_printf("%-4.9s\n", "0");
	return (0);
}
