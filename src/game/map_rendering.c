/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 15:44:11 by pdruart       #+#    #+#                 */
/*   Updated: 2022/02/25 17:40:50 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static COLOR	get_color_at(t_mlx_image *img, size_t x, size_t y)
{
	uint8_t	*pixel;

	pixel = img->pixels + (y * (4 * img->width)) + (4 * x);
	if (x > img->width || y > img->height)
		printf("TOO HIGH, x:%lu, width:%u, y:%lu, height:%u\n", x, img->width, y, img->height);
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

t_iv	decide_height(t_ray ray)
{
	float	result_height;

	// result_height = HEIGHT;
	// if (ray.len >= 1)
	result_height = HEIGHT / ray.eye_len;
	return ((t_iv){result_height, result_height});
}

void	map_hook(void *param)
{
	t_data *const	data = param;
	size_t			i;
	int				j;
	int				offset;
	// int				h;
	t_iv			heights;
	float			texel_step;
	float			darkness_mod;
	t_mlx_image		*texture;
	COLOR			c;
	float			y;

	i = 0;
	while (i < WIDTH)
	{
		heights = decide_height(data->rays[i]);
		j = 0;
		offset = 0;
		// if (heights.x > HEIGHT)
		// 	offset = (heights.x - HEIGHT) / 2;
		texture = decide_image(data, data->rays[i]);
		texel_step = ((float)texture->height) / ((float)heights.x);
		darkness_mod = 1.0 / fminf(5.0, fmaxf(1.0, 0.75 * (data->rays[i].len - 2.5)));
		// if (i == WIDTH / 2)
		// 	printf("i:%lu,len:%f\n", i, data->rays[i].len);
		// printf("step:%f,\n", texel_step);
		while (j + offset < heights.x)
		{
			c = get_color_at(texture,
					texture->width * (data->rays[i].pos_on_wall),
					j * texel_step);
			y = HEIGHT / 2 - (heights.x / 2) + j;
			// printf("[i:%lu,h:%i,texheight:%u,%i*%f=%f]\n", i, h, texture->height, j, texel_step, j * texel_step);
			if (y > 0 && y < HEIGHT)
				ml_draw_pixel(data->screen, i, y, ((ml_rgb(ml_color_r(c) * darkness_mod, ml_color_g(c) * darkness_mod, ml_color_b(c) * darkness_mod))));
			j++;
		}
		//for j=0 -> h
		//draw_pixel(i, HEIGHT / 2 - (h / 2) + j, get_mapped_pixel())
		// ml_draw_line(data->screen, (t_iv){i, HEIGHT / 2 - (h / 2)}, (t_iv){i, HEIGHT / 2 + (h / 2)}, get_color_at(decide_image(data, data->rays[i]), i * (data->rays[i].pos_on_wall), 0));
		i++;
	}
}
