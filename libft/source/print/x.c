/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 17:01:39 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/06 11:24:46 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <ft_int_limits.h>
#include <ft_memory.h>
#include <ft_print.h>

static char	ft_putnum(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return (n - 10 + 'a');
}

UINT	_ft_print_x(int fd, unsigned long long n)
{
	char	*buffer;
	int		index;

	buffer = ft_malloc_e(g_ullong_size + 1, "libft: print");
	index = g_ullong_size;
	while (n / 16)
	{
		buffer[index] = ft_putnum(n % 16);
		index--;
		n /= 16;
	}
	buffer[index] = ft_putnum(n % 16);
	write(fd, buffer + index, g_ullong_size + 1 - index);
	free(buffer);
	return (g_ullong_size + 1 - index);
}

UINT	_ft_print_x_n(int fd, ULLONG n)
{
	return (_ft_print_x(fd, n) + _ft_print_nl(fd));
}
