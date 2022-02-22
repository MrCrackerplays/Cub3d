/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:34:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 13:46:44 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_temp_init(t_data *data)
{
	data->player_pos = (t_fv){1.5, 1.5};
	data->player_angle = 2.0 * M_PI;
	data->fov = (90 * M_PI / 180);
	data->ray_skip = (1 / 1);
	data->ray_depth = 10;
	data->screen = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->minimap = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->map_pos = (t_fv){0, 0};
	data->map = ft_list_new();
	ft_list_add_back(data->map, ft_string_new("111111111111"));
	ft_list_add_back(data->map, ft_string_new("100000001111"));
	ft_list_add_back(data->map, ft_string_new("101110000111"));
	ft_list_add_back(data->map, ft_string_new("101010000011"));
	ft_list_add_back(data->map, ft_string_new("101000000001"));
	ft_list_add_back(data->map, ft_string_new("100000111011"));
	ft_list_add_back(data->map, ft_string_new("100001100001"));
	ft_list_add_back(data->map, ft_string_new("100001000001"));
	ft_list_add_back(data->map, ft_string_new("111111111111"));
	data->map_s = fmin(
			WIDTH / ((t_ft_string *)data->map->first->item)->len,
			HEIGHT / data->map->len);
}

static void	static_main_hook(void *param)
{
	t_data *const	data = param;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

int32_t	main(void)
{
	t_data	data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	static_temp_init(&data);
	mlx_image_to_window(data.mlx, data.screen, 0, 0);
	mlx_image_to_window(data.mlx, data.minimap, 0, 0);
	mlx_loop_hook(data.mlx, &static_main_hook, &data);
	mlx_loop_hook(data.mlx, &player_movement_hook, &data);
	mlx_loop_hook(data.mlx, &ray_cast_hook, &data);
	mlx_loop_hook(data.mlx, &minimap_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
