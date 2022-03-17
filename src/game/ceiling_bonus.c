/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ceiling_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 15:53:43 by pdruart       #+#    #+#                 */
/*   Updated: 2022/03/17 12:46:01 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static COLOR	darken(COLOR c, float distance)
{
	return (ml_color_darken(c,
			1.0 / fminf(15.0, fmaxf(1.0, 0.25 * (distance)))));
}

static void	magic_function_one(t_data *data, UINT y, float row_distance,
	float floor_data[4])
{
	UINT		x;
	float		height;
	t_mlx_image	*texture;

	texture = data->ceil_img;
	if (y > HEIGHT / 2 + data->player_ud_angle)
		texture = data->floor_img;
	x = 0;
	while (x < WIDTH)
	{
		height = fminf(fabsf(HEIGHT / data->rays[x].eye_len), 100000);
		if (data->rays[x].wall_type == '0' || data->rays[x].wall_type == '\0'
			|| y < floor(HEIGHT / 2 - height / 2 + data->player_ud_angle)
			|| y >= floor(HEIGHT / 2 + height / 2 + data->player_ud_angle))
		{
			ml_draw_pixel(data->screen, x, y, darken(ml_color_at(texture, \
				(int)(texture->width * (floor_data[0] \
				- floorf(floor_data[0]))) % texture->width, \
				(int)(texture->height * (floor_data[1] \
				- floorf(floor_data[1]))) % texture->height), row_distance));
		}
		floor_data[0] += floor_data[2];
		floor_data[1] += floor_data[3];
		x++;
	}
}

void	ceiling_hook(t_data *data)
{
	UINT	y;
	int		p;
	float	row_distance;
	t_fv	ray_dir_left;
	t_fv	ray_dir_right;

	y = 0;
	ray_dir_left.x = data->dir.x - data->plane.x;
	ray_dir_left.y = data->dir.y - data->plane.y;
	ray_dir_right.x = data->dir.x + data->plane.x;
	ray_dir_right.y = data->dir.y + data->plane.y;
	while (y < HEIGHT)
	{
		if (y > HEIGHT / 2 + data->player_ud_angle)
			p = (int)y - HEIGHT / 2 - data->player_ud_angle;
		else
			p = HEIGHT / 2 - (int)y + data->player_ud_angle;
		row_distance = ((float)(HEIGHT * 0.5)) / ((float)p);
		magic_function_one(data, y, row_distance, (float [4]){
			(data->player_pos.x + row_distance * ray_dir_left.x),
			(data->player_pos.y + row_distance * ray_dir_left.y),
			(row_distance * (ray_dir_right.x - ray_dir_left.x) / WIDTH),
			(row_distance * (ray_dir_right.y - ray_dir_left.y) / WIDTH)});
		y++;
	}
}
