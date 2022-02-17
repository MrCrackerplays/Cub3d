/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 19:37:58 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:33:02 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <ft_memory.h>
#include <ft_exit_error.h>
#include <ft_int_limits.h>

void	ft_list_add_front(t_ft_list *list, void *item)
{
	t_ft_list_node	*node;

	if (!list)
		ft_exit_error_d("libft: ft_list_add_front: got a NULL list");
	if (list->len == (int)g_uint_max)
		ft_exit_error_d("libft: ft_list_add_front: exeeded maximum list size");
	node = ft_malloc_e(sizeof(t_ft_list_node), "libft: ft_list_add_front");
	node->item = item;
	node->prev = NULL;
	if (list->first)
	{
		node->next = list->first;
		list->first->prev = node;
	}
	else
		node->next = NULL;
	list->first = node;
	if (!list->last)
		list->last = node;
	list->len++;
}

void	ft_list_add_back(t_ft_list *list, void *item)
{
	t_ft_list_node	*node;

	if (!list)
		ft_exit_error_d("libft: ft_list_add_back: got a NULL list");
	if (list->len == (int)g_uint_max)
		ft_exit_error_d("libft: ft_list_add_back: exeeded maximum list size");
	node = ft_malloc_e(sizeof(t_ft_list_node), "libft: ft_list_add_back");
	node->item = item;
	node->next = NULL;
	if (list->last)
	{
		node->prev = list->last;
		list->last->next = node;
	}
	else
		node->prev = NULL;
	list->last = node;
	if (!list->first)
		list->first = node;
	list->len++;
}
