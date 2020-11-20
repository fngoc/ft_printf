#include "libftprintf.h"

/*
** ft_parser_dot: парсер точности.
*/

void	ft_parser_type(char **str, t_parser *p)
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
	else
		(*p).type = 'N';
}

/*
** ft_parser_dot: парсер точности.
*/

void	ft_parser_dot(char **str, t_parser *p)
{
	if (**str == '.')
	{
		(*p).dot = '.';
		++*str;
	}
	else
	{
		(*p).dot = 'N';
		(*p).number_after_dot = 'N';
		return ;
	}
	if (**str == '*')
		(*p).number_after_dot = '*';
	else if (ft_isdigit(**str))
		(*p).number_after_dot = ft_atoi(*str);
	else
		(*p).number_after_dot = 'N';
	++*str;
}

/*
** ft_parser_width: парсер ширины.
*/

void	ft_parser_width(char **str, t_parser *p)
{
	if (**str == '*')
		(*p).width = '*';
	if (ft_isdigit(**str))
		(*p).width = ft_atoi(*str);
	else
		(*p).width = 'N';
	if ((*p).width != 'N')
		++*str;
}

/*
** ft_parser_flags: парсер флага.
*/

void	ft_parser_flags(char **str, t_parser *p)
{
	if (**str == '-')
		(*p).flags = '-';
	else if (**str == '0')
		(*p).flags = '0';
	else
		(*p).flags = 'N';
	if ((*p).flags != 'N')
		++*str;
}

/*
** ft_parser: парсер строки для печати.
*/

t_parser	ft_parser(char **str)
{
	t_parser p;

	ft_parser_flags(str, &p);
	ft_parser_width(str, &p);
	ft_parser_dot(str, &p);
	ft_parser_type(str, &p);

	return (p);
}
