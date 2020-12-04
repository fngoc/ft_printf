#include <stdio.h> /* Для printf */
#include <limits.h> /* Для INT_MIN и INT_MAX */

int	ft_printf(const char *format, ...);

int	main(void)
{
	int result1;
	int result2;
	puts("-------------------------------xX--------------------------------");
	printf("%x\n", -2147483648);
	ft_printf("%x\n", -2147483648);
	printf("%x\n", -2147483648);
	ft_printf("%x\n", -2147483648);
	result1 = ft_printf("|%0*.*x| |%07.3x| |%-.3X| |%010.9X|", -16, 10, -2312, 125, INT_MAX, INT_MIN);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%0*.*x| |%07.3x| |%-.3X| |%010.9X|", -16, 10, -2312, 125, INT_MAX, INT_MIN);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%0.0x| |%6.0x| |%0.1x| |%05.1x| |%0.0x| |%0.1x|", 0, 0, 0, 0, 1, 1);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%0.0x| |%6.0x| |%0.1x| |%05.1x| |%0.0x| |%0.1x|",  0, 0, 0, 0, 1, 1);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%-.0X| |%-6.0X| |%-.1X| |%-1.1X| |%-.0X| |%-.1X|", 0, 0, 0, 0, 1, 1);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%-.0X| |%-6.0X| |%-.1X| |%-1.1X| |%-.0X| |%-.1X|",  0, 0, 0, 0, 1, 1);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%*.*x| |%08.3x| |%0*x|", 8, 4, 2, 8375, -5, -54);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%*.*x| |%08.3x| |%0*x|", 8, 4, 2, 8375, -5, -54);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%0*x|", 7, -54);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%0*x|", 7, -54);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("%% *.5x 42 == |%*.5x|", 4, 42);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("%% *.5x 42 == |%*.5x|", 4, 42);
	printf("\t\tlb result: %d\n\n", result2);

	puts("--------------------------different types------------------------");
	result1 = ft_printf("string |%%| string |%-4.12d| |%9s| |%7d| |%-12x| |%X| |%x|", 'a', "bcd", 3, -5, 234, 0xac45);
	printf("\nmy result: %d\n", result1);
	result2 = printf("string |%%| string |%-4.12d| |%9s| |%7d| |%-12x| |%X| |%x|", 'a', "bcd", 3, -5, 234, 0xac45);
	printf("\nlb result: %d\n\n", result2);

	result1 = ft_printf("text text |%d| |%d| |%s| text |%c| |%X| |%x| |%p| text", -33, 33, "hello", 'g', -555, 555, "World");
	printf("\tmy result: %d\n", result1);
	result2 = printf("text text |%d| |%d| |%s| text |%c| |%X| |%x| |%p| text",  -33, 33, "hello", 'g', -555, 555, "World");
	printf("\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%s| |%3s| |%7s| |%9s| |%-7s|", "hello", "hello", "hello", "hello", "hello");
	printf("\tmy result: %d\n", result1);
	result2 = printf("|%s| |%3s| |%7s| |%9s| |%-7s|",  "hello", "hello", "hello", "hello", "hello");
	printf("\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%*s|", 6, "hello");
	printf("\tmy result: %d\n", result1);
	result2 = printf("|%*s|",  6, "hello");
	printf("\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%*s|", 10, "hello");
	printf("\tmy result: %d\n", result1);
	result2 = printf("|%*s|",  10, "hello");
	printf("\tlb result: %d\n\n", result2);

	puts("---------------------------------c--------------------------------");
	result1 = ft_printf("|%*c| |%.c| |%-5c|", 2, 'a', 'b', 'c');
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%*c| |%.c| |%-5c|", 2, 'a', 'b', 'c');
	printf("\t\tlb result: %d\n\n", result2);

	puts("--------------------------------s--------------------------------");
	result1 = ft_printf("|%*.*s| |%-4.19s| |%4.13s|", 17, 12, "это русский текст1", "this is a text2", "text2");
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%*.*s| |%-4.19s| |%4.13s|", 17, 12, "это русский текст1", "this is a text2", "text2");
	printf("\t\tlb result: %d\n\n", result2);

	printf("\tmy result: %d\n\n", ft_printf("|%3.6s| |%.1s|", NULL, NULL));
	printf("\tlb result: %d\n\n", printf("|%3.6s| |%.1s|", NULL, NULL));

	printf("\tmy result: %d\n\n", ft_printf("|%.*s|", -13, "hello"));
	printf("\tlb result: %d\n\n", printf("|%.*s|", -13, "hello"));

	puts("--------------------------------p--------------------------------");
	long long n1 = 12;
	result1 = ft_printf("|%24p| |%24p| |%16p|", &n1, &n1, &n1);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%24p| |%24p| |%16p|", &n1, &n1, &n1);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%24p| |%24p|", &n1, &n1);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%24p| |%24p|", &n1, &n1);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%.p| |%17p|", &n1, NULL);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%.p| |%17p|", &n1, NULL);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%-24p| |%-24p| |%-16p|", &n1, &n1, &n1);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%-24p| |%-24p| |%-16p|", &n1, &n1, &n1);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%-24p| |%-24p| |%-12p|", &n1, &n1, NULL);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%-24p| |%-24p| |%-12p|", &n1, &n1, NULL);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%-25p| |%-24p|", &n1, NULL);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%-25p| |%-24p|", &n1, NULL);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%-17p| |%-6p|", &n1, NULL);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%-17p| |%-6p|", &n1, NULL);
	printf("\t\tlb result: %d\n\n", result2);


	puts("-------------------------------di--------------------------------");
	result1 = ft_printf("|%-4.11d| |%-4.12i| |%-12.7d| |%06.4d|", INT_MIN, 234, 44444, -13);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%-4.11d| |%-4.12i| |%-12.7d| |%06.4d|", INT_MIN, 234, 44444, -13);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%*.*d| |%08.3d| |%0*i|", 8, 4, 2, 8375, -5, -54);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%*.*d| |%08.3d| |%0*i|", 8, 4, 2, 8375, -5, -54);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%0.0d| |%6.0d| |%0.1d| |%05.1d| |%0.0d| |%0.1d|", 0, 0, 0, 0, 1, 1);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%0.0d| |%6.0d| |%0.1d| |%05.1d| |%0.0d| |%0.1d|",  0, 0, 0, 0, 1, 1);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%-.0d| |%-6.0d| |%-.1d| |%-1.1d| |%-.0d| |%-.1d|", 0, 0, 0, 0, 1, 1);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%-.0d| |%-6.0d| |%-.1d| |%-1.1d| |%-.0d| |%-.1d|",  0, 0, 0, 0, 1, 1);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%0*i|", 7, -54);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%0*i|", 7, -54);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("%% *.5i 42 == |%*.5i|", 4, 42);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("%% *.5i 42 == |%*.5i|", 4, 42);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%.5d|", -2372);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%.5d|", -2372);
	printf("\t\tlb result: %d\n\n", result2);

	int result_pf;
	int result_my;
	result_pf = printf("pf: %%d_neg = |%d|\n", -42);
	result_my = ft_printf("my: %%d_neg = |%d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-d = |%-d|\n", 42);
	result_my = ft_printf("my: %%-d = |%-d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%0d = |%0d|\n", 42);
	result_my = ft_printf("my: %%0d = |%0d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-d_neg = |%-d|\n", -42);
	result_my = ft_printf("my: %%-d_neg = |%-d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%0d_neg = |%0d|\n", -42);
	result_my = ft_printf("my: %%0d_neg = |%0d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%3d = |%3d|\n", 42);
	result_my = ft_printf("my: %%3d = |%3d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-3d = |%-3d|\n", 42);
	result_my = ft_printf("my: %%-3d = |%-3d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%03d = |%03d|\n", 42);
	result_my = ft_printf("my: %%03d = |%03d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%3d_neg = |%3d|\n", -42);
	result_my = ft_printf("my: %%3d_neg = |%3d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-3d_neg = |%-3d|\n", -42);
	result_my = ft_printf("my: %%-3d_neg = |%-3d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%03d_neg = |%03d|\n", -42);
	result_my = ft_printf("my: %%03d_neg = |%03d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%13d = |%13d|\n", 424242);
	result_my = ft_printf("my: %%13d = |%13d|\n", 424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%13d_neg = |%13d|\n", -424242);
	result_my = ft_printf("my: %%13d_neg = |%13d|\n", -424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%6d = |%6d|\n", 424242);
	result_my = ft_printf("my: %%6d = |%6d|\n", 424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%6d_neg = |%6d|\n", -424242);
	result_my = ft_printf("my: %%6d_neg = |%6d|\n", -424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-13d = |%-13d|\n", 424242);
	result_my = ft_printf("my: %%-13d = |%-13d|\n", 424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-13d_neg = |%-13d|\n", -424242);
	result_my = ft_printf("my: %%-13d_neg = |%-13d|\n", -424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%013d = |%013d|\n", 424242);
	result_my = ft_printf("my: %%013d = |%013d|\n", 424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%013d_neg = |%013d|\n", -424242);
	result_my = ft_printf("my: %%013d_neg = |%013d|\n", -424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	result_pf = printf("pf: %%.d = |%.d|\n", 42);
	result_my = ft_printf("my: %%.d = |%.d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%.d_neg = |%.d|\n", -42);
	result_my = ft_printf("my: %%.d_neg = |%.d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-.d = |%-.d|\n", 42);
	result_my = ft_printf("my: %%-.d = |%-.d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%0.d = |%0.d|\n", 42);
	result_my = ft_printf("my: %%0.d = |%0.d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-.d_neg = |%-.d|\n", -42);
	result_my = ft_printf("my: %%-.d_neg = |%-.d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%0.d_neg = |%0.d|\n", -42);
	result_my = ft_printf("my: %%0.d_neg = |%0.d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%3.d = |%3.d|\n", 42);
	result_my = ft_printf("my: %%3.d = |%3.d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-3.d = |%-3.d|\n", 42);
	result_my = ft_printf("my: %%-3.d = |%-3.d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%03.d = |%03.d|\n", 42);
	result_my = ft_printf("my: %%03.d = |%03.d|\n", 42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%3.d_neg = |%3.d|\n", -42);
	result_my = ft_printf("my: %%3.d_neg = |%3.d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-3.d_neg = |%-3.d|\n", -42);
	result_my = ft_printf("my: %%-3.d_neg = |%-3.d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%03.d_neg = |%03.d|\n", -42);
	result_my = ft_printf("my: %%03.d_neg = |%03.d|\n", -42);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%13.d = |%13.d|\n", 424242);
	result_my = ft_printf("my: %%13.d = |%13.d|\n", 424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%13.d_neg = |%13.d|\n", -424242);
	result_my = ft_printf("my: %%13.d_neg = |%13.d|\n", -424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%6.d = |%6.d|\n", 424242);
	result_my = ft_printf("my: %%6.d = |%6.d|\n", 424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%6.d_neg = |%6.d|\n", -424242);
	result_my = ft_printf("my: %%6.d_neg = |%6.d|\n", -424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-13.d = |%-13.d|\n", 424242);
	result_my = ft_printf("my: %%-13.d = |%-13.d|\n", 424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%-13.d_neg = |%-13.d|\n", -424242);
	result_my = ft_printf("my: %%-13.d_neg = |%-13.d|\n", -424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%013.d = |%013.d|\n", 424242);
	result_my = ft_printf("my: %%013.d = |%013.d|\n", 424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);
	ft_printf("-------------------------------------\n");
	result_pf = printf("pf: %%013.d_neg = |%013.d|\n", -424242);
	result_my = ft_printf("my: %%013.d_neg = |%013.d|\n", -424242);
	ft_printf("len pf: %d\n", result_pf);
	ft_printf("len my: %d\n", result_my);

	puts("--------------------------------u--------------------------------");
	result1 = ft_printf("|%-5.12u| |%-.3u| |%*.0u| |%12u| |%-5.1u| |%2.6u|", -21, 144, -3, 1, INT_MAX, 10, 234);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%-5.12u| |%-.3u| |%*.0u| |%12u| |%-5.1u| |%2.6u|", -21, 144, -3, 1, INT_MAX, 10, 234);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%0.0u| |%6.0u| |%0.1u| |%05.1u| |%0.0u| |%0.1u|", 0, 0, 0, 0, 1, 1);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%0.0u| |%6.0u| |%0.1u| |%05.1u| |%0.0u| |%0.1u|",  0, 0, 0, 0, 1, 1);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%-.0u| |%-6.0u| |%-.1u| |%-1.1u| |%-.0u| |%-.1u|", 0, 0, 0, 0, 1, 1);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%-.0u| |%-6.0u| |%-.1u| |%-1.1u| |%-.0u| |%-.1u|",  0, 0, 0, 0, 1, 1);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%*.*u| |%08.3u| |%0*u|", 8, 4, 2, 8375, -5, -54);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%*.*u| |%08.3u| |%0*u|", 8, 4, 2, 8375, -5, -54);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%0*u|", 7, -54);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%0*u|", 7, -54);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("%% *.5u 42 == |%*.5u|", 4, 42);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("%% *.5u 42 == |%*.5u|", 4, 42);
	printf("\t\tlb result: %d\n\n", result2);

	result1 = ft_printf("|%.4u|", 2372);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%.4u|", 2372);
	printf("\t\tlb result: %d\n\n", result2);

	puts("--------------------------------%--------------------------------");
	result1 = ft_printf("|%d%%| |%%%%| |%%| |%3%| |%0.0%| |%-5%| |%-05%| |%-05%|", 432);
	printf("\t\tmy result: %d\n", result1);
	result2 = printf("|%d%%| |%%%%| |%%| |%3%| |%0.0%| |%-5%| |%-05%| |%-05%|", 432);
	printf("\t\tlb result: %d\n\n", result2);
	return (0);
}
