/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 13:42:47 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/06 11:24:06 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_int_types.h>
#include <ft_print.h>

UINT	_ft_print_a(int fd, char *s)
{
	UINT	i;

	if (!s)
		return (_ft_print_s(fd, s));
	i = 0;
	while (s[i])
	{
		if (s[i] >= ' ' && s[i] <= '~')
			_ft_print_c(fd, s[i]);
		else if (s[i] == '\n')
			_ft_print_s(fd, "\\n\n");
		else
		{
			_ft_print_s(fd, "{ch:");
			_ft_print_i(fd, s[i]);
			_ft_print_c(fd, '}');
		}
		i++;
	}
	return (i);
}

UINT	_ft_print_a_n(int fd, char *s)
{
	return (_ft_print_a(fd, s) + _ft_print_nl(fd));
}
