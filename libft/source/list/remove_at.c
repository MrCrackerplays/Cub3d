/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_at.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 18:14:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:35:35 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_list.h>
#include <ft_exit_error.h>
#include <ft_int_types.h>
#include <ft_print.h>

void	*ft_list_remove_at(t_ft_list *list, int index)
{
	t_ft_list_node	*node;
	void			*item;

	if (!list)
		ft_exit_error_d("libft: ft_list_remove_at: got a NULL list");
	index = _ft_list_true_index(list, index);
	if (index < 0 || index >= list->len)
		ft_exit_error_d("libft: ft_list_remove_at: index out of range");
	if (index == 0)
		return (ft_list_pop_front(list));
	else if (index == list->len - 1)
		return (ft_list_pop_back(list));
	node = _ft_list_node_at(list, index);
	item = node->item;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	list->len--;
	return (item);
}
