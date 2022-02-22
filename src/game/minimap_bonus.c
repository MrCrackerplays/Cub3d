/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 18:55:48 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 17:38:28 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_draw_walls(t_data *data)
{
	t_ft_string	*line;
	t_iv		cor;

	cor.y = 0;
	while (cor.y < data->map->len)
	{
		line = ft_list_item_at(data->map, cor.y);
		cor.x = 0;
		while (cor.x < line->len)
		{
			if (line->text[cor.x] == '1')
				ml_draw_box(data->minimap,
					(t_iv){cor.x * data->map_s + data->map_pos.x,
					cor.y * data->map_s + data->map_pos.y},
					(t_iv){data->map_s, data->map_s}, 0x00000080);
			else if (line->text[cor.x] == 'D')
				ml_draw_box(data->minimap,
					(t_iv){cor.x * data->map_s + data->map_pos.x,
					cor.y * data->map_s + data->map_pos.y},
					(t_iv){data->map_s, data->map_s}, 0xFF800080);
			else if (line->text[cor.x] == 'O')
				ml_draw_box(data->minimap,
					(t_iv){cor.x * data->map_s + data->map_pos.x,
					cor.y * data->map_s + data->map_pos.y},
					(t_iv){data->map_s, data->map_s}, 0x80400080);
			else if (line->text[cor.x] != '0')
				ml_draw_box(data->minimap,
					(t_iv){cor.x * data->map_s + data->map_pos.x,
					cor.y * data->map_s + data->map_pos.y},
					(t_iv){data->map_s, data->map_s}, 0x00FFFF80);
			cor.x++;
		}
		cor.y++;
	}
}

void	minimap_hook(void *param)
{
	t_data *const	data = param;
	size_t			i;

	i = 0;
	while (i < data->minimap->width * data->minimap->height)
	{
		mlx_putpixel(data->minimap, i, 0, 0);
		i++;
	}
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
	static_draw_walls(data);
}
