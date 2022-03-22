/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:53:15 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/18 16:16:13 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "map.h"

static void	static_test_tile(t_data *data, t_iv pos)
{
	char	c;

	c = map_get_at(data->map, pos.x, pos.y);
	if (is_in_wall_and_set_player(data, pos, c))
	{
		if (map_get_at(data->map, pos.x + 1, pos.y) == '\0'
			|| map_get_at(data->map, pos.x, pos.y + 1) == '\0'
			|| map_get_at(data->map, pos.x - 1, pos.y) == '\0'
			|| map_get_at(data->map, pos.x, pos.y - 1) == '\0'
			|| map_get_at(data->map, pos.x + 1, pos.y) == ' '
			|| map_get_at(data->map, pos.x, pos.y + 1) == ' '
			|| map_get_at(data->map, pos.x - 1, pos.y) == ' '
			|| map_get_at(data->map, pos.x, pos.y - 1) == ' ')
			ft_exit_error("Invalid map4.");
	}
	else if (c != ' ' && c != '1')
		ft_exit_error("Invalid map.5");
}

void	validate_map(t_data *data)
{
	t_iv	pos;

	data->player_pos = (t_fv){0, 0};
	data->player_angle = 2.0 * M_PI;
	pos.y = 0;
	while (pos.y < data->map->len - 1)
	{
		pos.x = 0;
		while ((UINT)pos.x
			< ((t_ft_string *)ft_list_item_at(data->map, pos.y))->len)
		{
			static_test_tile(data, pos);
			pos.x++;
		}
		pos.y++;
	}
	if (data->player_pos.x == 0)
		ft_exit_error("Invalid map.6");
}
