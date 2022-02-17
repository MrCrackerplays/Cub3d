/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 09:56:16 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:45:39 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_list.h>
#include <ft_memory.h>
#include <ft_int_types.h>
#include <ft_exit_error.h>

t_ft_list	*ft_string_split_to_list(char *string, char c)
{
	t_ft_list	*list;
	UINT		start;
	UINT		index;

	if (!string)
		ft_exit_error_d("libft: ft_string_split_to_list: got a NULL string");
	list = ft_list_new();
	start = 0;
	index = 0;
	while (string[index])
	{
		if (string[index] == c)
		{
			ft_list_add_back(list,
				_ft_string_new(string + start, index - start));
			start = index + 1;
		}
		index++;
	}
	ft_list_add_back(list, _ft_string_new(string + start, index));
	return (list);
}

t_ft_list	*ft_string_split_to_list_clean(char *string, char c)
{
	t_ft_list	*list;
	UINT		start;
	UINT		index;

	if (!string)
		ft_exit_error_d(
			"libft: ft_string_split_to_list_clean: got a NULL string");
	list = ft_list_new();
	start = 0;
	index = 0;
	while (string[index])
	{
		if (string[index] == c)
		{
			if (index - start != 0)
				ft_list_add_back(list,
					_ft_string_new(string + start, index - start));
			start = index + 1;
		}
		index++;
	}
	if (index - start != 0)
		ft_list_add_back(list, _ft_string_new(string + start, index));
	return (list);
}

char	**ft_string_split_to_array(char *string, char c)
{
	t_ft_list	*list;
	char		**array;

	list = ft_string_split_to_list(string, c);
	array = (char **)ft_list_to_array(list);
	ft_list_free(list);
	return (array);
}

char	**ft_string_split_to_array_clean(char *string, char c)
{
	t_ft_list	*list;
	char		**array;

	list = ft_string_split_to_list_clean(string, c);
	array = (char **)ft_list_to_array(list);
	ft_list_free(list);
	return (array);
}
