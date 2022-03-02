/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:53:15 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/02 12:38:22 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static bool	static_is_in_wall_and_set_player(t_data *data, t_iv pos, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (data->player_pos.x != 0)
			ft_exit_error("Reassigning player position.");
		data->player_pos = (t_fv){pos.x + .5, pos.y + .5};
		if (c == 'N')
			data->player_angle += M_PI + M_PI / 2;
		else if (c == 'S')
			data->player_angle += M_PI / 2;
		else if (c == 'W')
			data->player_angle += M_PI;
		return (true);
	}	
	return (c == '0' || c == 'D' || c == 'O' || c == 'M');
}

static void	static_test_tile(t_data *data, t_iv pos)
{
	char	c;

	c = map_get_at(data->map, pos.x, pos.y);
	if (static_is_in_wall_and_set_player(data, pos, c))
	{
		if (map_get_at(data->map, pos.x + 1, pos.y) == '\0'
			|| map_get_at(data->map, pos.x, pos.y + 1) == '\0'
			|| map_get_at(data->map, pos.x - 1, pos.y) == '\0'
			|| map_get_at(data->map, pos.x, pos.y - 1) == '\0'
			|| map_get_at(data->map, pos.x + 1, pos.y) == ' '
			|| map_get_at(data->map, pos.x, pos.y + 1) == ' '
			|| map_get_at(data->map, pos.x - 1, pos.y) == ' '
			|| map_get_at(data->map, pos.x, pos.y - 1) == ' ')
			ft_exit_error("Invalid map.");
	}
	else if (c != ' ' && c != '1')
		ft_exit_error("Invalid map.");
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
}
