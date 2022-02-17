/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 19:45:35 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:35:15 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <stdlib.h>
#include <ft_exit_error.h>

void	*ft_list_pop_front(t_ft_list *list)
{
	t_ft_list_node	*node;
	void			*item;

	if (!list)
		ft_exit_error_d("libft: ft_list_pop_front: got a NULL list");
	if (!list->first)
		ft_exit_error_d("libft: ft_list_pop_front: poping empty list");
	node = list->first;
	item = node->item;
	list->first = node->next;
	if (list->first)
		list->first->prev = NULL;
	else
		list->last = NULL;
	free(node);
	list->len--;
	return (item);
}

void	*ft_list_pop_back(t_ft_list *list)
{
	t_ft_list_node	*node;
	void			*item;

	if (!list)
		ft_exit_error_d("libft: ft_list_pop_back: got a NULL list");
	if (!list->last)
		ft_exit_error_d("libft: ft_list_pop_back: poping empty list");
	node = list->last;
	item = node->item;
	list->last = node->prev;
	if (list->last)
		list->last->next = NULL;
	else
		list->first = NULL;
	free(node);
	list->len--;
	return (item);
}
