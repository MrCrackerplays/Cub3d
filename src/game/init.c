/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 14:57:00 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/02 12:56:25 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_minimap(t_data *data)
{
	t_ft_list_node	*longest;
	t_ft_list_node	*parse;

	parse = data->map->first;
	longest = parse;
	while (parse)
	{
		if (((t_ft_string *)parse->item)->len
			> ((t_ft_string *)longest->item)->len)
			longest = parse;
		parse = parse->next;
	}
	data->minimap = mlx_new_image(data->mlx, WIDTH / 4, HEIGHT / 4);
	data->map_s = fmin(
			data->minimap->width / ((t_ft_string *)longest->item)->len,
			data->minimap->height / data->map->len);
	data->map_pos = (t_fv){-data->map_s, -data->map_s};
}

void	init_game(t_data *data)
{
	data->fov = (70 * M_PI / 180);
	data->ray_depth = 30;
	data->player_ud_angle = 1;
	data->screen = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	data->door = mlx_new_image(data->mlx, 120, 120);
	ml_draw_box(data->door, (t_iv){0, 0}, (t_iv){60, 60}, 0x000000FF);
	ml_draw_box(data->door, (t_iv){60, 60}, (t_iv){60, 60}, 0xFF0000FF);
	init_minimap(data);
}
