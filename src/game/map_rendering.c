/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 15:44:11 by pdruart       #+#    #+#                 */
/*   Updated: 2022/03/22 16:19:47 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_mlx_image	*decide_image(t_data *data, t_ray ray)
{
	if (ray.wall_face == 'n')
		return (data->north);
	if (ray.wall_face == 'e')
		return (data->east);
	if (ray.wall_face == 's')
		return (data->south);
	if (ray.wall_face == 'w')
		return (data->west);
	return (NULL);
}

static void	static_draw_line(
	t_data *data, t_mlx_image *texture, int i, float args[2])
{
	const float	texel_step = args[0];
	const float	height = args[1];
	COLOR		c;
	int			j;

	if (height > HEIGHT)
		j = fmaxf((height - HEIGHT) / 2, 0);
	else
		j = 0;
	while (j < height && j + (HEIGHT - height) / 2 < HEIGHT)
	{
		c = ml_color_at(texture, texture->width
				* (data->rays[i].pos_on_wall), j * texel_step);
		ml_draw_pixel(data->screen, i, j + (int)(HEIGHT - height) / 2, c);
		j++;
	}
}

void	map_hook(t_data *data)
{
	int			i;
	float		texel_step;
	float		height;
	t_mlx_image	*texture;

	i = -1;
	while (i < WIDTH - 1)
	{
		i++;
		texture = decide_image(data, data->rays[i]);
		if (!texture)
			continue ;
		height = fminf(fabsf(HEIGHT / data->rays[i].eye_len), 10000000) + 2;
		texel_step = ((float)texture->height) / height;
		static_draw_line(data, texture, i,
			(float [2]){texel_step, height});
	}
}
