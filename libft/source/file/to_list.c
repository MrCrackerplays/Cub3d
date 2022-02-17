/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_list.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 16:35:01 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/08 19:26:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_file.h>
#include <ft_list.h>
#include <ft_exit_error.h>

t_ft_list	*ft_file_to_list(char *file_name)
{
	t_ft_list	*list;
	int			fd;

	fd = ft_file_open(file_name, O_RDONLY);
	list = ft_list_new();
	ft_list_add_back(list, ft_file_next_line(fd));
	while (list->last->item != NULL)
		ft_list_add_back(list, ft_file_next_line(fd));
	return (list);
}
