/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 18:31:38 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:34:07 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_list.h>
#include <ft_memory.h>
#include <ft_exit_error.h>

void	ft_list_free(t_ft_list	*list)
{
	if (!list)
		ft_exit_error_d("libft: ft_list_free: got a NULL list");
	while (list->first)
		ft_list_pop_front(list);
	free(list);
}

void	ft_list_free_all(t_ft_list	*list, void (*del)(void *))
{
	if (!list)
		ft_exit_error_d("libft: ft_list_free_all: got a NULL list");
	if (!del)
		ft_exit_error_d("libft: ft_list_free_all: got a NULL function");
	while (list->first)
		(*del)(ft_list_pop_front(list));
	free(list);
}
