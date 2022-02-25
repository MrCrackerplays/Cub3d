/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 15:44:11 by pdruart       #+#    #+#                 */
/*   Updated: 2022/02/25 19:44:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static COLOR	get_color_at(t_mlx_image *img, size_t x, size_t y)
{
	uint8_t	*pixel;

	pixel = img->pixels + (y * (4 * img->width)) + (4 * x);
	return (ml_rgba(pixel[0], pixel[1], pixel[2], pixel[3]));
}

t_mlx_image	*decide_image(t_data *data, t_ray ray)
{
	if (ray.wall_type == 'D')
		return (data->door);
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
	t_data *data, t_mlx_image *texture, int i, float args[3])
{
	const float			texel_step = args[0];
	const float			height = args[1];
	const float			darkness_mod = args[2];
	COLOR				c;
	int					j;

	if (height > HEIGHT)
		j = height / 2 - HEIGHT / 2;
	else
		j = 0;
	while (j < height && HEIGHT / 2 - (height / 2) + j < HEIGHT)
	{
		c = get_color_at(texture, texture->width
				* (data->rays[i].pos_on_wall), j * texel_step);
		ml_draw_pixel(data->screen, i, HEIGHT / 2 - (height / 2) + j,
			ml_rgb(ml_color_r(c) * darkness_mod, ml_color_g(c)
				* darkness_mod, ml_color_b(c) * darkness_mod));
		j++;
	}
}

void	map_hook(t_data *data)
{
	int			i;
	float		texel_step;
	float		height;
	float		darkness_mod;
	t_mlx_image	*texture;

	i = 0;
	while (i < WIDTH)
	{
		height = HEIGHT / data->rays[i].eye_len;
		texture = decide_image(data, data->rays[i]);
		texel_step = ((float)texture->height) / height;
		darkness_mod
			= 1.0 / fminf(5.0, fmaxf(1.0, 0.75 * (data->rays[i].len - 2.5)));
		static_draw_line(data, texture, i,
			(float [3]){texel_step, height, darkness_mod});
		i++;
	}
}
