/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_array.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 11:58:51 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:35:57 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <ft_memory.h>
#include <ft_exit_error.h>

void	**ft_list_to_array(t_ft_list *list)
{
	void			**new_array;
	t_ft_list_node	*parse_node;
	int				index;

	if (!list)
		ft_exit_error_d("libft: ft_list_to_array: got a NULL list");
	new_array = ft_malloc_e(sizeof(void *) * (list->len + 1),
			"libft: ft_list_to_array");
	parse_node = list->first;
	index = 0;
	while (parse_node)
	{
		new_array[index] = parse_node->item;
		index++;
		parse_node = parse_node->next;
	}
	new_array[index] = NULL;
	return (new_array);
}
