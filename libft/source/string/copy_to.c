/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_to.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 18:08:04 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:44:07 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>
#include <ft_exit_error.h>
#include <ft_memory.h>

t_ft_string	*ft_string_copy_to(t_ft_string *des, t_ft_string *src)
{
	if (!des || !src)
		ft_exit_error_d("libft: ft_string_copy_to: got a NULL string");
	free(des->text);
	des->len = src->len;
	des->text = ft_malloc_e(sizeof(char) * (src->len + 1), "libft: ft_string");
	ft_strcpy(des->text, src->text);
	return (des);
}

t_ft_string	*ft_string_copy_to_s(t_ft_string *des, char *src)
{
	int	length;

	if (!des)
		ft_exit_error_d("libft: ft_string_copy_to_s: got a NULL string");
	if (!src)
		ft_exit_error_d("libft: ft_string_copy_to_s: got a NULL cstring");
	free(des->text);
	length = ft_strlen(src);
	des->len = length;
	des->text = ft_malloc_e(sizeof(char) * (length + 1),
			"libft: ft_string_copy_to_s");
	ft_strcpy(des->text, src);
	return (des);
}
