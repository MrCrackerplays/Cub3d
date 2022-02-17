/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _list_find_node_with_item.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 16:02:49 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/01/31 13:18:34 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_list.h>

t_ft_list_node	*_ft_list_find_node_w_item(t_ft_list *list, void *item)
{
	t_ft_list_node	*parse_node;

	parse_node = list->first;
	while (parse_node)
	{
		if (parse_node->item == item)
			return (parse_node);
		parse_node = parse_node->next;
	}
	return (NULL);
}

t_ft_list_node	*_ft_list_find_node_w_item_back(t_ft_list *list, void *item)
{
	t_ft_list_node	*parse_node;

	parse_node = list->last;
	while (parse_node)
	{
		if (parse_node->item == item)
			return (parse_node);
		parse_node = parse_node->prev;
	}
	return (NULL);
}
