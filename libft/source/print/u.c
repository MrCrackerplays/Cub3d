/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_u.c                                          :+:    :+:            */
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

static void	static_u_to_buffer(char *buffer, int *index, ULLONG n)
{
	if (n >= 10)
		static_u_to_buffer(buffer, index, n / 10);
	buffer[*index] = (n % 10) + '0';
	*index += 1;
}

UINT	_ft_print_u(int fd, ULLONG n)
{
	char	*buffer;
	int		index;

	index = 0;
	buffer = ft_malloc_e(g_ullong_size, "libft: print");
	static_u_to_buffer(buffer, &index, n);
	write(fd, buffer, index);
	free(buffer);
	return (index);
}

UINT	_ft_print_u_n(int fd, ULLONG n)
{
	return (_ft_print_u(fd, n) + _ft_print_nl(fd));
}
