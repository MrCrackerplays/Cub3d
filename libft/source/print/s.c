/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_s.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 13:42:47 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/06 11:23:04 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_int_types.h>
#include <ft_print.h>

UINT	_ft_print_s(int fd, char *s)
{
	UINT	len;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
	return (len);
}

UINT	_ft_print_s_n(int fd, char *s)
{
	return (_ft_print_s(fd, s) + _ft_print_nl(fd));
}
