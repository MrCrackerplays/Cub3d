/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:34:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/28 14:00:01 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	static_main_hook(void *param)
{
	t_data *const	data = param;
	t_iv			cord;

	cord.x = 0;
	while (cord.x < WIDTH)
	{
		cord.y = 0;
		while (cord.y < HEIGHT)
		{
			data->bitmap[cord.x][cord.y] = data->bitmode;
			cord.y++;
		}
		cord.x++;
	}
	data->bitmode = !data->bitmode;
	data->game_time += data->mlx->delta_time;
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
	mlx_loop_hook(data.mlx, (void (*)(void *))ceiling_hook, &data);
	mlx_loop_hook(data.mlx, (void (*)(void *))map_hook, &data);
	mlx_loop_hook(data.mlx, (void (*)(void *))sprite_hook, &data);
	mlx_loop_hook(data.mlx, &player_movement_hook, &data);
	mlx_loop_hook(data.mlx, (void (*)(void *))minimap_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	exit(EXIT_SUCCESS);
}
