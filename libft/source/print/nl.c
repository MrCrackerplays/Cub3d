/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_nl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 13:30:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/06 11:24:46 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ft_int_types.h>
#include <ft_memory.h>

UINT	_ft_print_nl(int fd)
{
	write(fd, "\n", 1);
	return (1);
}

UINT	_ft_print_nl_c(int fd, UINT n)
{
	char	*buffer;
	UINT	index;

	buffer = ft_malloc_e(sizeof(char) * n, "libft");
	index = 0;
	while (index < n)
	{
		buffer[index] = '\n';
		index++;
	}
	write(fd, buffer, n);
	free(buffer);
	return (n);
}
