/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 18:55:48 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 13:36:09 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_draw_walls(t_data *data)
{
	t_ft_string	*line;
	int			x;
	int			y;

	y = 0;
	while (y < data->map->len)
	{
		line = ft_list_item_at(data->map, y);
		x = 0;
		while (x < line->len)
		{
			if (line->text[x] == '1')
				ml_draw_box(data->minimap,
					(t_iv){x * data->map_s + data->map_pos.x,
					y * data->map_s + data->map_pos.y},
					(t_iv){data->map_s, data->map_s},
					0xFFFFFF40);
			x++;
		}
		y++;
	}
}

void	minimap_hook(void *param)
{
	t_data *const	data = param;
	size_t			i;

	i = 0;
	while (i < data->minimap->width * data->minimap->height)
	{
		mlx_putpixel(data->minimap, i, 0, 64);
		i++;
	}
	static_draw_walls(data);
	i = 0;
	while (i < WIDTH)
	{
		ml_draw_line(data->minimap,
			(t_iv){
			data->player_pos.x * data->map_s + data->map_pos.x,
			data->player_pos.y * data->map_s + data->map_pos.y},
			(t_iv){
			data->rays[i].hit_pos.x * data->map_s + data->map_pos.x,
			data->rays[i].hit_pos.y * data->map_s + data->map_pos.y},
			0xFFFFFF80);
		i += data->ray_skip;
	}
}
