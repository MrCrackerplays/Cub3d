/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 17:01:39 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/08 13:33:49 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_int_types.h>
#include <ft_print.h>
#include <ft_string.h>

UINT	_ft_print_m(int fd, t_ft_string *s)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s->text, s->len);
	return (1);
}

UINT	_ft_print_m_n(int fd, t_ft_string *s)
{
	return (_ft_print_m(fd, s) + _ft_print_nl(fd));
}
