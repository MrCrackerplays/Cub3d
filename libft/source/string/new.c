/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 17:32:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:44:29 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_memory.h>
#include <ft_exit_error.h>

t_ft_string	*ft_string_new(char *src)
{
	t_ft_string	*new_string;
	int			length;

	if (!src)
		ft_exit_error_d("libft: ft_string_new: got a NULL cstring");
	new_string = ft_malloc_e(sizeof(t_ft_string), "libft: ft_string_new");
	length = ft_strlen(src);
	new_string->len = length;
	new_string->text = ft_malloc_e(sizeof(char) * (length + 1),
			"libft: string");
	ft_strcpy(new_string->text, src);
	return (new_string);
}
