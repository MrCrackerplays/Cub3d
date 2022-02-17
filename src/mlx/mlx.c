/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:34:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/17 17:47:15 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 400
#define HEIGHT 250

t_mlx_image	*g_img;
int			g_x;
int			g_y;

void	hook(void *param)
{
	const COLOR		black = ml_rgba(0, 0, 0, 127);

	for (size_t x = 0; x < g_img->width; x++)
		for (size_t y = 0; y < g_img->height; y++)
			mlx_putpixel(g_img, x, y, black);
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_quit(param);
	if (mlx_is_key_down(param, MLX_KEY_W))
		g_y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_S))
		g_y += 5;
	if (mlx_is_key_down(param, MLX_KEY_A))
		g_x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_D))
		g_x += 5;
	for (size_t x = 0; x < 25; x++)
		for (size_t y = 0; y < 25; y++)
			mlx_putpixel(g_img, g_x + x, g_y + y, ml_rgb(255, 255, 0));
}

int32_t	main(void)
{
	t_mlx	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_x = 0;
	g_y = 0;
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(g_img->pixels, 255, g_img->width * g_img->width * sizeof(int));
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
