/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _new_formated.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 22:40:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:46:39 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_print.h>
#include <ft_int_types.h>
#include <ft_memory.h>
#include <ft_exit_error.h>

static void	static_select_and_format(t_ft_string *string, char format,
		void *args)
{
	t_ft_string	*tmp;

	if (format == 'm')
		tmp = args;
	else if (format == 's')
	{
		ft_string_cat_to_s(string, args);
		return ;
	}
	else if (format == 'i')
		tmp = ft_string_new_i((LLONG)args);
	else if (format == 'u')
		tmp = ft_string_new_u((ULLONG)args);
	else
	{
		ft_string_cat_to_c(string, (LLONG)args);
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

t_ft_string	*_ft_string_new_f(char *format, void **args)
{
	t_ft_string	*new_string;
	UINT		start;
	UINT		index;

	if (!format)
		ft_exit_error_d("libft: ft_string_new_f: get a NULL format");
	new_string = _ft_string_new("", 0);
	start = 0;
	index = 0;
	while (format[index])
	{
		if (format[index] == '%' && static_is_string_format(format[index + 1]))
		{
			static_try_add(new_string, format + start, index - start);
			static_select_and_format(new_string, format[index + 1], *args);
			args++;
			start = index + 2;
			index++;
		}
		index++;
	}
	static_try_add(new_string, format + start, index - start);
	return (new_string);
}
