/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_u.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 22:40:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:44:51 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_print.h>
#include <ft_int_types.h>
#include <ft_int_limits.h>
#include <ft_memory.h>

static void	static_u_to_buffer(char *buffer, int *index, ULLONG n)
{
	if (n >= 10)
		static_u_to_buffer(buffer, index, n / 10);
	buffer[*index] = (n % 10) + '0';
	*index += 1;
}

t_ft_string	*ft_string_new_u(ULLONG n)
{
	t_ft_string	*new_string;
	char		*buffer;
	int			index;

	index = 0;
	buffer = ft_malloc_e(g_ullong_size, "libft: ft_string_new_u");
	static_u_to_buffer(buffer, &index, n);
	buffer[index] = '\0';
	new_string = ft_malloc_e(sizeof(t_ft_string), "libft: ft_string_new_u");
	new_string->text = buffer;
	new_string->len = index;
	return (new_string);
}
