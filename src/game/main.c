/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:34:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/28 14:00:07 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_main_hook(void *param)
{
	t_data *const	data = param;
	UINT			i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (i < WIDTH * (HEIGHT / 2))
			mlx_putpixel(data->screen, i, 0, data->roof);
		else if (i > WIDTH * (HEIGHT / 2))
			mlx_putpixel(data->screen, i, 0, data->floor);
		i++;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
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
	mlx_loop_hook(data.mlx, (void (*)(void *))map_hook, &data);
	mlx_loop_hook(data.mlx, &player_movement_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	exit(EXIT_SUCCESS);
}
