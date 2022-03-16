/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 15:44:11 by pdruart       #+#    #+#                 */
/*   Updated: 2022/03/16 17:51:13 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_mlx_image	*decide_image(t_data *data, t_ray ray)
{
	if (ray.wall_type == 'D')
		return (data->door[((int)(data->game_time / .5)) % 3]);
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
	const float	texel_step = args[0];
	const float	height = args[1];
	const float	darkness_mod = args[2];
	COLOR		c;
	int			j;

	if (height > HEIGHT)
		j = fmaxf((height - HEIGHT) / 2 - data->player_ud_angle, 0);
	else
		j = 0;
	while (j < height && data->player_ud_angle
		+ j + (HEIGHT - height) / 2 < HEIGHT)
	{
		c = ml_color_at(texture, texture->width
				* (data->rays[i].pos_on_wall), j * texel_step);
		ml_draw_pixel(data->screen, i, (int)data->player_ud_angle
			+ j + (int)(HEIGHT - height) / 2, ml_color_darken(c, darkness_mod));
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

	i = -1;
	while (i < WIDTH - 1)
	{
		i++;
		texture = decide_image(data, data->rays[i]);
		if (!texture)
			continue ;
		height = fminf(fabsf(HEIGHT / data->rays[i].eye_len), 10000000);
		texel_step = ((float)texture->height) / height;
		darkness_mod
			= 1.0 / fminf(15.0, fmaxf(1.0, 0.25 * (data->rays[i].len)));
		static_draw_line(data, texture, i,
			(float [3]){texel_step, height, darkness_mod});
	}
}
