/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cat_to.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 18:23:58 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:44:14 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>
#include <ft_exit_error.h>
#include <ft_memory.h>

t_ft_string	*ft_string_cat_to(t_ft_string *des, t_ft_string *src)
{
	char	*new_text;

	if (!des || !src)
		ft_exit_error_d("libft: ft_string_cat_to: got a NULL string");
	if (src->len == 0)
		return (des);
	new_text = ft_malloc_e(sizeof(char) * (des->len + src->len + 1),
			"libft: ft_string_cat_to");
	ft_strcpy(new_text, des->text);
	ft_strcpy(new_text + des->len, src->text);
	free(des->text);
	des->text = new_text;
	des->len += src->len;
	return (des);
}

t_ft_string	*ft_string_cat_to_s(t_ft_string *des, char *src)
{
	char	*new_text;
	int		length;

	if (!des || !src)
		ft_exit_error_d("libft: ft_string_cat_to_s: got a NULL string");
	length = ft_strlen(src);
	if (length == 0)
		return (des);
	new_text = ft_malloc_e(sizeof(char) * (des->len + length + 1),
			"libft: ft_string_cat_to_s");
	ft_strcpy(new_text, des->text);
	ft_strcpy(new_text + des->len, src);
	free(des->text);
	des->text = new_text;
	des->len += length;
	return (des);
}

t_ft_string	*ft_string_cat_to_c(t_ft_string *des, char c)
{
	char	*new_text;

	if (!des)
		ft_exit_error_d("libft: ft_string_cat_to_c: got a NULL string");
	new_text = ft_malloc_e(sizeof(char) * (des->len + 2),
			"libft: ft_string_cat_to_c");
	ft_strcpy(new_text, des->text);
	new_text[des->len] = c;
	new_text[des->len + 1] = '\0';
	free(des->text);
	des->text = new_text;
	des->len += 2;
	return (des);
}
