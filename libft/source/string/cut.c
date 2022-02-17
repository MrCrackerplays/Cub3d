/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cut.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 17:32:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:44:00 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_memory.h>
#include <ft_exit_error.h>
#include <ft_int_types.h>

t_ft_string	*ft_string_cut(t_ft_string *string, UINT start, UINT length)
{
	t_ft_string	*new_string;

	if (!string)
		ft_exit_error_d("libft: ft_string_cut: got a NULL string");
	if ((ULLONG)start + (ULLONG)length > string->len)
		ft_exit_error_d("libft: ft_string_cut: out of range");
	new_string = _ft_string_new(string->text + start, length);
	return (new_string);
}

t_ft_string	*ft_string_cutout(t_ft_string *string, UINT start, UINT length)
{
	t_ft_string	*new_string;
	int			index;

	new_string = ft_string_cut(string, start, length);
	index = 0;
	while (start + length + index < string->len)
	{
		string->text[start + index] = string->text[start + length + index];
		index++;
	}
	string->text[start + index] = '\0';
	string->len = start + index;
	return (new_string);
}
