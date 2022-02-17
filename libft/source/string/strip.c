/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strip.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 17:54:49 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:45:58 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>
#include <ft_exit_error.h>

char	*ft_string_strip(t_ft_string *string)
{
	char	*text;

	if (!string)
		ft_exit_error_d("libft: ft_string_strip: got a NULL string");
	text = string->text;
	ft_string_free(string);
	return (text);
}

UINT	ft_string_strip_l(t_ft_string *string)
{
	UINT	len;

	if (!string)
		ft_exit_error_d("libft: ft_string_strip_l: got a NULL string");
	len = string->len;
	ft_string_free(string);
	return (len);
}
