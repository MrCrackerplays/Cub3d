/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   replace_at.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 15:55:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:35:39 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_list.h>
#include <ft_exit_error.h>

void	*ft_list_replace_at(t_ft_list *list, int index, void *item)
{
	t_ft_list_node	*node;
	void			*old_item;

	if (!list)
		ft_exit_error_d("libft: ft_list_replace_at: got a NULL list");
	node = _ft_list_node_at(list, index);
	if (!node)
		return (NULL);
	old_item = node->item;
	node->item = item;
	return (old_item);
}
