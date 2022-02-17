/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 19:39:44 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 18:31:47 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_int_types.h>
#include <ft_exit_error.h>

int	ft_strcmp(char *src1, char *src2)
{
	UINT	index;

	if (!src1 || !src2)
		ft_exit_error_d("libft: ft_strcmp: got a NULL cstring");
	index = 0;
	while (src1[index] && src1[index] == src2[index])
		index++;
	return (src1[index] - src2[index]);
}
