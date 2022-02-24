/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   import.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 15:42:35 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/24 19:13:49 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <fcntl.h>

static void	static_test_access(char *file_path)
{
	const int	fd = open(file_path, O_RDONLY);

	close(fd);
	if (fd < 0)
		ft_exit_error("Can't load map.");
}

static void	static_remove_newlines(t_data *data)
{
	t_ft_list_node	*parse_node;

	parse_node = data->map->first;
	while (parse_node != data->map->last->prev)
	{
		((t_ft_string *)parse_node->item)
			->text[((t_ft_string *)parse_node->item)->len - 1] = '\0';
		((t_ft_string *)parse_node->item)
			->len--;
		parse_node = parse_node->next;
	}
}

void	import_map(char *file_path, t_data *data)
{
	if (ft_strcmp(file_path + ft_strlen(file_path) - 4, ".cub"))
		ft_exit_error("Wrong file type.");
	static_test_access(file_path);
	data->map = ft_file_to_list(file_path);
	if (data->map->len < 9)
		ft_exit_error("Invalid map.");
	static_remove_newlines(data);
	data->north = NULL;
	data->south = NULL;
	data->east = NULL;
	data->west = NULL;
	format_map(data, false, false, NULL);
	validate_map(data);
	free(ft_list_pop_back(data->map));
}
