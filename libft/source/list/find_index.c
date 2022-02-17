/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_index.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 16:02:49 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:33:09 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <ft_int_types.h>
#include <ft_exit_error.h>

int	ft_list_find_index(t_ft_list *list, void *item)
{
	t_ft_list_node	*parse_node;
	int				index;

	if (!list)
		ft_exit_error_d("libft: ft_list_find_index: got a NULL list");
	if (!list->first)
		return (-1);
	index = 0;
	parse_node = list->first;
	while (parse_node)
	{
		if (parse_node->item == item)
			return (index);
		index++;
		parse_node = parse_node->next;
	}
	return (-1);
}
