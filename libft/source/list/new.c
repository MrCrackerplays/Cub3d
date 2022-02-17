/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 18:31:38 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:34:30 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <ft_memory.h>

t_ft_list	*ft_list_new(void)
{
	t_ft_list	*new_list;

	new_list = ft_malloc_e(sizeof(t_ft_list), "libft: ft_list_new");
	new_list->first = NULL;
	new_list->last = NULL;
	new_list->len = 0;
	return (new_list);
}
