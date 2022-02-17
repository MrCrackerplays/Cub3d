/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _true_index.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 16:24:03 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/08 19:28:42 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

int	_ft_list_true_index(t_ft_list *list, int index)
{
	if (index < 0)
		return (list->len + index);
	return (index);
}
