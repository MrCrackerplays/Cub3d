/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 18:55:48 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/17 16:30:40 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_draw_wall(t_data *data, t_iv cor, char type)
{
	if (type == '1')
		ml_draw_box(data->minimap,
			(t_iv){cor.x * data->map_s + data->map_pos.x,
			cor.y * data->map_s + data->map_pos.y},
			(t_iv){data->map_s, data->map_s}, 0xa0000000);
	else if (type == 'D')
		ml_draw_box(data->minimap,
			(t_iv){cor.x * data->map_s + data->map_pos.x,
			cor.y * data->map_s + data->map_pos.y},
			(t_iv){data->map_s, data->map_s}, 0xa00080FF);
	else if (type == 'O')
		ml_draw_box(data->minimap,
			(t_iv){cor.x * data->map_s + data->map_pos.x,
			cor.y * data->map_s + data->map_pos.y},
			(t_iv){data->map_s, data->map_s}, 0xa0004080);
	else if (type == 'M')
		ml_draw_box(data->minimap,
			(t_iv){cor.x * data->map_s + data->map_pos.x,
			cor.y * data->map_s + data->map_pos.y},
			(t_iv){data->map_s, data->map_s}, 0xa05ff089);
	else if (type == 'W' || type == 'E' || type == 'N' || type == 'S')
		ml_draw_box(data->minimap,
			(t_iv){cor.x * data->map_s + data->map_pos.x,
			cor.y * data->map_s + data->map_pos.y},
			(t_iv){data->map_s, data->map_s}, 0xa0FFFF00);
}

static void	static_draw_walls(t_data *data)
{
	t_ft_string	*line;
	t_iv		cor;

	cor.y = 0;
	while (cor.y < data->map->len)
	{
		line = ft_list_item_at(data->map, cor.y);
		cor.x = 0;
		while (cor.x < (int)line->len)
		{
			static_draw_wall(data, cor, line->text[cor.x]);
			cor.x++;
		}
		cor.y++;
	}
}

void	minimap_hook(t_data *data)
{
	size_t			i;
	t_iv			cord;

	cord.x = 0;
	while (cord.x < (int)data->minimap->width)
	{
		cord.y = 0;
		while (cord.y < (int)data->minimap->height)
		{
			ml_draw_pixel(data->minimap, cord.x, cord.y, 0x000000ff);
			cord.y++;
		}
		cord.x++;
	}
	static_draw_walls(data);
	i = 0;
	while (i < WIDTH)
	{
		ml_draw_line(data->minimap, (t_iv){data->player_pos.x * data->map_s
			+ data->map_pos.x, data->player_pos.y * data->map_s
			+ data->map_pos.y}, (t_iv){data->rays[i].hit_pos_i.x * data->map_s
			+ data->map_pos.x, data->rays[i].hit_pos_i.y * data->map_s
			+ data->map_pos.y}, 0xa0FFFFFF);
		i++;
	}
}
