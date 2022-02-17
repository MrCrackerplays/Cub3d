/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 16:21:28 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:34:17 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <ft_memory.h>
#include <ft_exit_error.h>
#include <ft_int_limits.h>

void	ft_list_insert(t_ft_list *list, int index, void *item)
{
	t_ft_list_node	*node;
	t_ft_list_node	*new_node;

	if (!list)
		ft_exit_error_d("libft: ft_list_insert: got a NULL list");
	if (index >= list->len || index < -list->len)
		ft_exit_error_d("libft: ft_list_insert: insertion out of range");
	if (index == 0)
		ft_list_add_front(list, item);
	else
	{
		node = _ft_list_node_at(list, index);
		new_node = ft_malloc_e(sizeof(t_ft_list_node), "libft: ft_list_insert");
		new_node->item = item;
		new_node->next = node;
		new_node->prev = node->prev;
		node->prev->next = new_node;
		node->prev = new_node;
		list->len++;
	}
}
