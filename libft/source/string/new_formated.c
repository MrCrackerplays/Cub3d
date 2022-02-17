/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_formated.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 22:40:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:44:34 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <ft_print.h>
#include <ft_int_types.h>
#include <ft_memory.h>
#include <ft_exit_error.h>

static void	static_select_and_format(t_ft_string *string, char format,
		va_list list)
{
	t_ft_string	*tmp;

	if (format == 'm')
		tmp = va_arg(list, t_ft_string *);
	else if (format == 's')
	{
		ft_string_cat_to_s(string, va_arg(list, char *));
		return ;
	}
	else if (format == 'i')
		tmp = ft_string_new_i(va_arg(list, LLONG));
	else if (format == 'u')
		tmp = ft_string_new_u(va_arg(list, ULLONG));
	else
	{
		ft_string_cat_to_c(string, va_arg(list, int));
		return ;
	}
	ft_string_cat_to(string, tmp);
	ft_string_free(tmp);
}

static BOOL	static_is_string_format(char c)
{
	if (c == 'm' || c == 'i' || c == 's' || c == 'u' || c == 'c')
		return (TRUE);
	return (FALSE);
}

static void	static_try_add(t_ft_string *string, char *text, UINT length)
{
	t_ft_string	*new_string;

	if (length <= 0)
		return ;
	new_string = _ft_string_new(text, length);
	ft_string_cat_to(string, new_string);
	ft_string_free(new_string);
}

t_ft_string	*_ft_string_new_f_parser(char *format, va_list list)
{
	t_ft_string	*new_string;
	UINT		start;
	UINT		index;

	new_string = _ft_string_new("", 0);
	start = 0;
	index = 0;
	while (format[index])
	{
		if (format[index] == '%' && static_is_string_format(format[index + 1]))
		{
			static_try_add(new_string, format + start, index - start);
			static_select_and_format(new_string, format[index + 1], list);
			start = index + 2;
			index++;
		}
		index++;
	}
	static_try_add(new_string, format + start, index - start);
	return (new_string);
}

t_ft_string	*ft_string_new_f(char *format, ...)
{
	t_ft_string	*new_string;
	va_list		list;

	if (!format)
		ft_exit_error_d("libft: ft_string_new_f: get a NULL format");
	va_start(list, format);
	new_string = _ft_string_new_f_parser(format, list);
	va_end(list);
	return (new_string);
}
