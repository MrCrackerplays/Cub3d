/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 17:32:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:43:55 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>
#include <ft_memory.h>
#include <ft_exit_error.h>

void	ft_string_free(t_ft_string *string)
{
	if (!string)
		ft_exit_error_d("libft: ft_string_free: got a NULL string");
	free(string->text);
	free(string);
}
