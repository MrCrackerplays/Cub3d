/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   item_at.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 19:53:28 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:34:23 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_list.h>
#include <ft_exit_error.h>

void	*ft_list_item_at(t_ft_list *list, int index)
{
	t_ft_list_node	*node;

	if (!list)
		ft_exit_error_d("libft: ft_list_item_at: got a NULL list");
	node = _ft_list_node_at(list, index);
	if (node)
		return (node->item);
	return (NULL);
}
