/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 17:01:39 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/06 11:23:35 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_int_types.h>
#include <ft_print.h>

UINT	_ft_print_c(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

UINT	_ft_print_c_n(int fd, char c)
{
	return (_ft_print_c(fd, c) + _ft_print_nl(fd));
}
