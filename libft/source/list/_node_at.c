/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _node_at.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 19:53:28 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 17:13:22 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_list.h>
#include <ft_exit_error.h>

static t_ft_list_node	*static_find_item_front(t_ft_list *list, int index)
{
	t_ft_list_node	*parse_node;

	parse_node = list->first;
	while (parse_node && index)
	{
		parse_node = parse_node->next;
		index--;
	}
	return (parse_node);
}

// static t_ft_list_node	*static_find_item_back(t_ft_list *list, int index)
// {
// 	t_ft_list_node	*parse_node;

// 	parse_node = list->last;
// 	while (parse_node && index < list->len - 1)
// 	{
// 		parse_node = parse_node->prev;
// 		index++;
// 	}
// 	return (parse_node);
// }

t_ft_list_node	*_ft_list_node_at(t_ft_list *list, int index)
{
	if (!list)
		return (NULL);
	index = _ft_list_true_index(list, index);
	if (index < 0 || index >= list->len)
		ft_exit_error_d("libft: _ft_list_node_at: index out of range");
	return (static_find_item_front(list, index));
}
