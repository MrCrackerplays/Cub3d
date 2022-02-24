/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:34:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/24 16:10:20 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_main_hook(void *param)
{
	t_data *const	data = param;
	int				i;

	i = 0;
	while (i < data->screen->width * data->screen->height / 2)
	{
		mlx_putpixel(data->screen, i, 0, data->roof);
		i++;
	}
	while (i < data->screen->width * data->screen->height)
	{
		mlx_putpixel(data->screen, i, 0, data->floor);
		i++;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

int32_t	main(void)
{
	t_data	data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	init_game(&data);
	mlx_image_to_window(data.mlx, data.screen, 0, 0);
	mlx_image_to_window(data.mlx, data.minimap, 0, 0);
	mlx_loop_hook(data.mlx, &static_main_hook, &data);
	mlx_loop_hook(data.mlx, &player_movement_hook, &data);
	mlx_loop_hook(data.mlx, &ray_cast_hook, &data);
	mlx_loop_hook(data.mlx, &map_hook, &data);
	mlx_loop_hook(data.mlx, &minimap_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
