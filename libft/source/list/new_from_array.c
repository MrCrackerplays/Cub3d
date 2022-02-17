/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_from_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 18:31:38 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:34:43 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <ft_memory.h>
#include <ft_exit_error.h>

t_ft_list	*ft_list_new_from_array(void **array)
{
	t_ft_list	*new_list;
	int			index;

	if (!array)
		ft_exit_error_d("libft: ft_list_new_from_array: got a NULL array");
	new_list = ft_list_new();
	index = 0;
	while (array[index])
	{
		ft_list_add_back(new_list, array[index]);
		index++;
	}
	return (new_list);
}

t_ft_list	*ft_list_new_from_array_n(void **array, int lenght)
{
	t_ft_list	*new_list;
	int			index;

	if (!array)
		ft_exit_error_d("libft: ft_list_new_from_array_n: got a NULL array");
	if (lenght <= 0)
		ft_exit_error_d(
			"libft: ft_list_new_from_array_n: length of array is less then 1");
	new_list = ft_list_new();
	index = 0;
	while (index < lenght)
	{
		ft_list_add_back(new_list, array[index]);
		index++;
	}
	return (new_list);
}
