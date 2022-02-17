/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _formated.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 16:54:32 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:37:25 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_print.h>
#include <ft_exit_error.h>

UINT	_ft_print(int fd, char *format, void **args)
{
	t_ft_string	*string;

	if (fd < 0)
		ft_exit_error("libft: _ft_print: invalid file descriptor");
	if (!format)
		ft_exit_error("libft: _ft_print: get a NULL format");
	string = _ft_string_new_f(format, args);
	_ft_print_m(fd, string);
	return (ft_string_strip_l(string));
}
