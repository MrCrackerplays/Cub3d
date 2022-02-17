/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 18:33:19 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 18:31:47 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_exit_error.h>

int	ft_strlen(char *src)
{
	int	length;

	if (!src)
		ft_exit_error_d("libft: ft_strlen: got a NULL cstring");
	length = 0;
	while (src[length])
		length++;
	return (length);
}
