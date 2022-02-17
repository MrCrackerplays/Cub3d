/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 13:08:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/17 13:53:35 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>
#include <libft.h>

BOOL	is_info(t_ft_string *line)
{
	if (line->len < 4)
		;
}

BOOL	is_map_char(char c)
{
	return (c == '0' || c == '1'
		|| c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

t_map	*import_map_from_file(char *file_name)
{
	t_map		*new_map;
	t_ft_string	*line;

	new_map = ft_malloc(sizeof(t_map));
	new_map->lines = ft_file_to_list(file_name);
	line = ft_list_pop_front(new_map->lines);
	while (line->text[0])
	{
		/* code */
	}
	ft_list_add_front(new_map->lines, line);
	return (new_map);
	_ft_list_print_m();
}

char	map_get_at(t_map *map, UINT x, UINT y)
{
	t_ft_string	*line;

	if (y >= map->lines->len)
		return ('\0');
	line = ft_list_item_at(map->lines, y);
	if (x >= line->len)
		return ('\0');
	return (line->text[x]);
}
