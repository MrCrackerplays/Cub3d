/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:21:32 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:35:46 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_list.h>
#include <ft_exit_error.h>

t_ft_list	*ft_list_reverse(t_ft_list *list)
{
	t_ft_list_node	*right_node;
	t_ft_list_node	*left_node;
	void			*temp_item;

	if (!list)
		ft_exit_error_d("libft: ft_list_reverse: got a NULL list");
	right_node = list->last;
	left_node = list->first;
	while (left_node != right_node && left_node->prev != right_node)
	{
		temp_item = right_node->item;
		right_node->item = left_node->item;
		left_node->item = temp_item;
		right_node = right_node->prev;
		left_node = left_node->next;
	}
	return (list);
}

t_ft_list	*ft_list_reverse_new(t_ft_list *list)
{
	t_ft_list		*new_list;
	t_ft_list_node	*parse_node;

	if (!list)
		ft_exit_error_d("libft: ft_list_reverse_new: got a NULL list");
	new_list = ft_list_new();
	parse_node = list->last;
	while (parse_node)
	{
		ft_list_add_back(new_list, parse_node->item);
		parse_node = parse_node->prev;
	}
	return (new_list);
}
