/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 15:44:11 by pdruart       #+#    #+#                 */
/*   Updated: 2022/02/24 17:59:07 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static COLOR	get_color_at(t_mlx_image *img, size_t x, size_t y)
{
	uint8_t	*pixel;

	pixel = img->pixels + (y * (4 * WIDTH)) + (4 * x);
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

int	decide_height(t_ray ray)
{
	float	result_height;

	result_height = HEIGHT;
	if (ray.len >= 1)
		result_height = HEIGHT / ray.len;
	return (result_height);
}

void	map_hook(void *param)
{
	t_data *const	data = param;
	size_t			i;
	int				h;

	i = 0;
	while (i < WIDTH)
	{
		h = decide_height(data->rays[i]);
		ml_draw_line(data->screen, (t_iv){i, HEIGHT / 2 - (h / 2)}, (t_iv){i, HEIGHT / 2 + (h / 2)}, get_color_at(decide_image(data, data->rays[i]), i * (data->rays[i].pos_on_wall), 0));
		;
		i++;
	}
}
