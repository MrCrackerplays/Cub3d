/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_at.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 13:37:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/26 17:21:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	map_get_at(t_ft_list *map, UINT x, UINT y)
{
	t_ft_string	*line;

	if (y >= (UINT)map->len)
		return ('\0');
	line = ft_list_item_at(map, y);
	if (x >= line->len)
		return ('\0');
	return (line->text[x]);
}
