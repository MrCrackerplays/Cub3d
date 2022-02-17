/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 22:05:05 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:43:50 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>
#include <ft_exit_error.h>
#include <ft_memory.h>
#include <ft_int_types.h>

t_ft_string	*ft_string_insert(t_ft_string *des, UINT index, t_ft_string *src)
{
	char	*new_text;

	if (!des || !src)
		ft_exit_error_d("libft: ft_string_insert: got a NULL string");
	if (index > des->len)
		ft_exit_error_d("libft: ft_string_insert: index out of range");
	if (src->len == 0)
		return (des);
	new_text = ft_malloc_e(sizeof(char) * (des->len + src->len + 1),
			"libft: ft_string_insert");
	ft_strncpy(new_text, des->text, index);
	ft_strcpy(new_text + index, src->text);
	ft_strcpy(new_text + index + src->len, des->text + index);
	free(des->text);
	des->text = new_text;
	des->len = des->len + src->len;
	return (des);
}

t_ft_string	*ft_string_insert_s(t_ft_string *des, UINT index, char *src)
{
	char	*new_text;
	UINT	length;

	if (!des || !src)
		ft_exit_error_d("libft: ft_string_insert_s: got a NULL string");
	if (index > des->len)
		ft_exit_error_d("libft: ft_string_insert_s: index out of range");
	length = ft_strlen(src);
	if (length == 0)
		return (des);
	new_text = ft_malloc_e(sizeof(char) * (des->len + length + 1),
			"libft: ft_string_insert_s");
	ft_strncpy(new_text, des->text, index);
	ft_strcpy(new_text + index, src);
	ft_strcpy(new_text + index + length, des->text + index);
	free(des->text);
	des->text = new_text;
	des->len = des->len + length;
	return (des);
}
