/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 14:57:00 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/17 16:37:18 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_bonus(t_data *data)
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
	mlx_image_to_window(data->mlx, data->minimap, 0, 0);
	data->map_s = fmin(
			data->minimap->width / ((t_ft_string *)longest->item)->len,
			data->minimap->height / data->map->len);
	data->map_pos = (t_fv){-data->map_s, -data->map_s};
}

void	init_game(t_data *data)
{
	data->bitmode = 1;
	data->fov = (80 * M_PI / 180);
	data->ray_depth = 30;
	data->player_ud_angle = 1;
	data->screen = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	data->game_time = 0;
	mlx_image_to_window(data->mlx, data->screen, 0, 0);
	init_bonus(data);
}
