#include "libftprintf.h" /* Моя библиотека */
#include <stdio.h> /* Для printf */

int		main(void)
{
//	char *a = "123vxcz";
//
//	printf("Adress printf: %p\n", &a);
//	ft_printf("Adress ft_printf: %p\n", &a);
//
//	printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
//	ft_printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
//
//	printf("%u\n", -11);
//	ft_printf("%u\n", -11);
	
//	printf("%d\n", dec_in_bin(5));
//	ft_printf("%d\n", dec_in_bin(5));

//	ft_printf("%.5d\n", 5);
	
	/* Тестирование */
//	printf("%7.9s\n", "helloItsme");
//	printf("%");
	t_parser a;
//	a = ft_printf("Hello %-0.5dxworld\n", 6);
//	printf("Start pars:\n%c\n%d\n%c\n%d\n%c\n", a.flags, a.width, a.dot, a.number_after_dot, a.type);
	a = ft_printf("%d\n%s\n%c\n", 21, "lol", 't');
	return (0);
}
