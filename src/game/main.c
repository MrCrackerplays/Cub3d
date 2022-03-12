/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:34:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/12 20:00:49 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_main_hook(void *param)
{
	t_data *const	data = param;
	UINT			i;

	i = 0;
	// printf("fps:%f,depth:%i\n", 1.0 / data->mlx->delta_time, data->ray_depth);
	data->game_time += data->mlx->delta_time;
	// while (i < data->screen->width * data->screen->height / 2
	// 	+ data->player_ud_angle * data->screen->width)
	// {
	// 	mlx_putpixel(data->screen, i, 0, data->roof);
	// 	i++;
	// }
	// while (i < data->screen->width * data->screen->height)
	// {
	// 	mlx_putpixel(data->screen, i, 0, data->floor);
	// 	i++;
	// }
	if (data->ray_depth > 2 && mlx_is_key_down(data->mlx, MLX_KEY_KP_SUBTRACT))
		data->ray_depth--;
	if (data->ray_depth < 200 && mlx_is_key_down(data->mlx, MLX_KEY_KP_ADD))
		data->ray_depth++;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	// ft_print(1, "\x1b[A{ FPS: %i }\n", (int)(1 / data->mlx->delta_time));
}

int32_t	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		ft_exit_error("No map given.");
	if (argc > 2)
		ft_exit_error("Too many arguments.");
	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	import_map(argv[1], &data);
	init_game(&data);
	mlx_loop_hook(data.mlx, &static_main_hook, &data);
	mlx_loop_hook(data.mlx, &ray_cast_hook, &data);
	mlx_loop_hook(data.mlx, (void (*)(void *))ceiling_hook, &data);
	mlx_loop_hook(data.mlx, (void (*)(void *))map_hook, &data);
	mlx_loop_hook(data.mlx, (void (*)(void *))sprite_hook, &data);
	mlx_loop_hook(data.mlx, &player_movement_hook, &data);
	mlx_loop_hook(data.mlx, (void (*)(void *))minimap_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	exit(EXIT_SUCCESS);
}
