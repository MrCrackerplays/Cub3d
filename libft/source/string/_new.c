/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _new.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 17:32:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:41:54 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_memory.h>
#include <ft_exit_error.h>

t_ft_string	*_ft_string_new(char *src, UINT length)
{
	t_ft_string	*new_string;

	if (!src)
		ft_exit_error_d("libft: _ft_string_new: got a null cstring");
	new_string = ft_malloc_e(sizeof(t_ft_string), "libft: _ft_string_new");
	new_string->len = length;
	new_string->text = ft_malloc_e(sizeof(char) * (length + 1),
			"libft: _ft_string_new");
	ft_strncpy(new_string->text, src, length);
	new_string->text[length] = '\0';
	return (new_string);
}
