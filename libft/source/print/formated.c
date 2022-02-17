/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formated.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 16:54:32 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:20:44 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <ft_int_types.h>
#include <ft_print.h>
#include <ft_string.h>
#include <ft_exit_error.h>

UINT	ft_print(int fd, char *format, ...)
{
	t_ft_string	*new_string;
	va_list		list;

	if (fd < 0)
		ft_exit_error("libft: print: invalid file descriptor");
	if (!format)
		ft_exit_error("libft: print: get a NULL format");
	va_start(list, format);
	new_string = _ft_string_new_f_parser(format, list);
	va_end(list);
	_ft_print_m(fd, new_string);
	return (ft_string_strip_l(new_string));
}
