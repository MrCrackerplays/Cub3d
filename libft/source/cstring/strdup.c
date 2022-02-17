/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strdup.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 12:34:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 18:34:50 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>
#include <ft_exit_error.h>
#include <ft_cstring.h>

char	*ft_strdup(char *src)
{
	char	*new_string;

	if (!src)
		ft_exit_error_d("libft: ft_strdup: got a NULL cstring");
	new_string = ft_malloc_e(sizeof(char) * (ft_strlen(src) + 1),
			"libft: ft_strdup");
	ft_strcpy(new_string, src);
	return (new_string);
}

char	*ft_strndup(char *src, size_t n)
{
	char	*new_string;

	if (!src)
		ft_exit_error_d("libft: ft_strdup: got a NULL cstring");
	new_string = ft_malloc_e(sizeof(char) * (n + 1),
			"libft: ft_strdup");
	ft_strncpy(new_string, src, n);
	return (new_string);
}
