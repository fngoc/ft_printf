#include "libftprintf.h" /* Моя библиотека */

int		main(void)
{
	/* Тестирование */
//	char *a = "123vxcz";
//	printf("Adress printf: %p\n", &a);
//	ft_printf("Adress ft_printf: %p\n", &a);
//	printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
//	ft_printf("Hello it's me %s, year %d and my first letter %c %%\n", "OLEG", 38, 'o');
//	printf("%u\n", -11);
//	ft_printf("%u\n", -11);
//	printf("%d\n", dec_in_bin(5));
//	ft_printf("%d\n", dec_in_bin(5));
//	ft_printf("%.5d\n", 5);
//	t_parser a;
//	printf("%7.9s\n", "helloItsme");
//	printf("%"); /* Вызывает ошибку */
//	printf("Hello %-4.5d world\n", 6);
//	a = ft_printf("Hello %.5d world\n", 6);
//	ft_printf("%3.3s%7.7s\n", "hello", "world");
//	char *s_hidden = "hi1low\0don't print me lol\0";
//	printf("%d\n", ft_strlen(s_hidden));
	printf("%-*.*s\n", -7, -3, "yolo");
	int len = ft_printf("%-*.*s\n", -7, -3, "yolo");
	printf("len: %d\n", len);

//	ft_printf("%d\n%s\n%c\n%%\n%s\n%d\n", 21, "lol", 't', "kek", 17);
//	printf("Start pars:\n%c\n%d\n%d\n%c\n", a.flags, a.width, a.number_after_dot, a.type);
	return (0);
}
