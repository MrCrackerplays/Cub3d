/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   [TEMP]map_get_at.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 13:37:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 13:37:14 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* TO BE DELETED */
char	map_get_at(t_ft_list *map, UINT x, UINT y)
{
	t_ft_string	*line;

	if (x < 0 || y < 0)
		return ('\0');
	if (y >= map->len)
		return ('\0');
	line = ft_list_item_at(map, y);
	if (x >= line->len)
		return ('\0');
	return (line->text[x]);
}
