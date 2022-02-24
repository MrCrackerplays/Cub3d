/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 14:57:00 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/24 16:56:29 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_minimap(t_data *data)
{
	data->minimap = mlx_new_image(data->mlx, WIDTH / 4, HEIGHT / 4);
	data->map_pos = (t_fv){0, 0};
	data->map_s = fmin(
			data->minimap->width / ((t_ft_string *)data->map->first->item)->len,
			data->minimap->height / data->map->len);
}

void	init_game(t_data *data)
{
	data->player_pos = (t_fv){1.5, 1.5};
	data->player_angle = 2.0 * M_PI;
	data->fov = (90 * M_PI / 180);
	data->ray_skip = (1 / 1);
	data->ray_depth = 10;
	data->screen = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->roof = ml_rgb(64, 128, 128 + 64);
	data->floor = ml_rgb(32, 128, 64);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	data->map = ft_list_new();
	ft_list_add_back(data->map, ft_string_new("1111111111111"));
	ft_list_add_back(data->map, ft_string_new("1E00000001111"));
	ft_list_add_back(data->map, ft_string_new("1000000000111"));
	ft_list_add_back(data->map, ft_string_new("1000000000011"));
	ft_list_add_back(data->map, ft_string_new("1011000000001"));
	ft_list_add_back(data->map, ft_string_new("1010000111D11"));
	ft_list_add_back(data->map, ft_string_new("10D0001100001"));
	ft_list_add_back(data->map, ft_string_new("1110001000001"));
	ft_list_add_back(data->map, ft_string_new("1111111111111"));
	data->north = mlx_new_image(data->mlx, 120, 120);
	data->east = mlx_new_image(data->mlx, 120, 120);
	data->south = mlx_new_image(data->mlx, 120, 120);
	data->west = mlx_new_image(data->mlx, 120, 120);
	data->door = mlx_new_image(data->mlx, 120, 120);
	ml_draw_box(data->north, (t_iv){0,0}, (t_iv){120,120}, 0xFF0000FF);
	ml_draw_box(data->east, (t_iv){0,0}, (t_iv){120,120}, 0xFFFFFFFF);
	ml_draw_box(data->south, (t_iv){0,0}, (t_iv){120,120}, 0x00FF00FF);
	ml_draw_box(data->west, (t_iv){0,0}, (t_iv){120,120}, 0x0000FFFF);
	ml_draw_box(data->door, (t_iv){0,0}, (t_iv){120,120}, 0x000000FF);
	init_minimap(data);
}
