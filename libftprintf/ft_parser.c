#include "libftprintf.h"

/*
** ft_parser_type: парсер типа.
*/

static void	ft_parser_type(char **str, t_parser *p)
{
	if (**str == 'd')
		(*p).type = 'd';
	else if (**str == 'i')
		(*p).type = 'i';
	else if (**str == 's')
		(*p).type = 's';
	else if (**str == 'c')
		(*p).type = 'c';
	else if (**str == 'p')
		(*p).type = 'p';
	else if (**str == 'u')
		(*p).type = 'u';
	else if (**str == 'x')
		(*p).type = 'x';
	else if (**str == 'X')
		(*p).type = 'X';
	else if (**str == '%')
		(*p).type = '%';
	else
		(*p).type = 'N';
}

/*
** ft_parser_dot: парсер точности.
*/

static void	ft_parser_number_after_dot(char **str, t_parser *p)
{
	if (**str == '.')
	{
		(*p).dot = '.';
		++*str;
		while (**str == '.')
			++*str;
		while (p->number_after_dot == '0' ||
			   ft_isdigit(**str) || **str == '*')
		{
			if (**str == '*')
			{
				(*p).number_after_dot = '*';
				++*str;
			}
			else if (ft_isdigit(**str))
			{
				(*p).number_after_dot = ft_atoi(*str);
				*str = *str + ft_digit_num((*p).number_after_dot);
			}
		}
	}
	else
		return ;
}

/*
** ft_parser_width: парсер ширины.
*/

static void	ft_parser_width(char **str, t_parser *p)
{
	if (**str == '*')
	{
		(*p).width = '*';
		++*str;
	}
	else if (ft_isdigit(**str))
	{
		(*p).width = ft_atoi(*str);
		*str = *str + ft_digit_num((*p).width);
	}
}

/*
** ft_parser_flags: парсер флага.
*/

static void	ft_parser_flags(char **str, t_parser *p)
{
	int flag;

	flag = 0;
	while (**str == '0' || **str == '-')
	{
		if (**str == '-')
		{
			flag = 1;
			(*p).flags = '-';
		}
		if (**str == '0' && !flag)
			(*p).flags = '0';
		++*str;
	}
}

/*
** ft_parser: парсер флагов, ширины, строки и типа.
*/

void	ft_parser(char **str, t_parser *parser)
{
	ft_newtparser(parser);
	ft_parser_flags(str, parser);
	ft_parser_width(str, parser);
	ft_parser_number_after_dot(str, parser);
	ft_parser_type(str, parser);
}
