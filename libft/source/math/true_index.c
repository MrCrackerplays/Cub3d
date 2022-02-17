/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   true_index.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 19:28:54 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/08 19:29:06 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_int_types.h>

int	ft_true_index(UINT size, int index)
{
	if (index < 0)
		return (size + index);
	return (index);
}
