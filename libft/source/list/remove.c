/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 18:14:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:35:29 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_list.h>
#include <ft_exit_error.h>
#include <ft_int_types.h>

BOOL	ft_list_remove(t_ft_list *list, void *item)
{
	t_ft_list_node	*node;

	if (!list)
		ft_exit_error_d("libft: ft_list_remove: got a NULL list");
	if (item == list->first->item)
	{
		ft_list_pop_front(list);
		return (TRUE);
	}
	node = _ft_list_find_node_w_item(list, item);
	if (!node)
		return (FALSE);
	if (node == list->last->item)
	{
		ft_list_pop_back(list);
		return (TRUE);
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	list->len--;
	return (TRUE);
}

BOOL	ft_list_remove_back(t_ft_list *list, void *item)
{
	t_ft_list_node	*node;

	if (!list)
		ft_exit_error_d("libft: ft_list_remove_back: got a NULL list");
	if (item == list->last->item)
	{
		ft_list_pop_back(list);
		return (TRUE);
	}
	node = _ft_list_find_node_w_item_back(list, item);
	if (!node)
		return (FALSE);
	if (node == list->first->item)
	{
		ft_list_pop_front(list);
		return (TRUE);
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	list->len--;
	return (TRUE);
}
