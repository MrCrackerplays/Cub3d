/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_casting.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 20:39:44 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/25 17:53:52 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static t_ray	static_ray_with_face_hit(t_ray ray, t_iv dir, char func)
{
	if (func == 'x')
	{
		if (dir.x == 1)
			ray.wall_face = 'e';
		else
			ray.wall_face = 'w';
		if (dir.x == 1)
			ray.pos_on_wall = ray.hit_pos.y - (int)ray.hit_pos.y;
		else
			ray.pos_on_wall = 1 - (ray.hit_pos.y - (int)ray.hit_pos.y);
	}
	else
	{
		if (dir.y == 1)
			ray.wall_face = 's';
		else
			ray.wall_face = 'n';
		if (dir.y == 1)
			ray.pos_on_wall = 1 - (ray.hit_pos.x - (int)ray.hit_pos.x);
		else
			ray.pos_on_wall = ray.hit_pos.x - (int)ray.hit_pos.x;
	}
	return (ray);
}

static t_ray
	static_ray_x(t_data *data, float tan_res, t_iv dir, int cor)
{
	t_ray		ray;
	int			i;

	if (dir.x == -1)
		cor = 1;
	ray.hit_pos.x = (int)data->player_pos.x + dir.x + cor;
	ray.hit_pos.y = (float)(data->player_pos.x - (int)data->player_pos.x);
	if (dir.x == 1)
		ray.hit_pos.y = (1 - ray.hit_pos.y);
	ray.hit_pos.y = data->player_pos.y + (ray.hit_pos.y * tan_res * dir.x);
	i = 0;
	ray.wall_type = is_wall(
			map_get_at(data->map, ray.hit_pos.x - cor, ray.hit_pos.y));
	while (i < data->ray_depth && !ray.wall_type)
	{
		ray.hit_pos.x += dir.x;
		ray.hit_pos.y += (tan_res * dir.x);
		ray.wall_type = is_wall(
				map_get_at(data->map, ray.hit_pos.x - cor, ray.hit_pos.y));
		i++;
	}
	ray.len = sqrtf(powf(data->player_pos.x - ray.hit_pos.x, 2)
			+ powf(data->player_pos.y - ray.hit_pos.y, 2));
	ray.hit_wall_pos = (t_iv){ray.hit_pos.x - cor, ray.hit_pos.y};
	return (static_ray_with_face_hit(ray, dir, 'x'));
}

static t_ray
	static_ray_y(t_data *data, float tan_res, t_iv dir, int cor)
{
	t_ray		ray;
	int			i;

	if (dir.y == -1)
		cor = 1;
	ray.hit_pos.y = (int)data->player_pos.y + dir.y + cor;
	ray.hit_pos.x = data->player_pos.y - (int)data->player_pos.y;
	if (dir.y == 1)
		ray.hit_pos.x = 1 - ray.hit_pos.x;
	ray.hit_pos.x = data->player_pos.x + ray.hit_pos.x * tan_res * (-dir.y);
	i = 0;
	ray.wall_type = is_wall(
			map_get_at(data->map, ray.hit_pos.x, ray.hit_pos.y - cor));
	while (i < data->ray_depth && !ray.wall_type)
	{
		ray.hit_pos.y += dir.y;
		ray.hit_pos.x += (tan_res * (-dir.y));
		ray.wall_type = is_wall(
				map_get_at(data->map, ray.hit_pos.x, ray.hit_pos.y - cor));
		i++;
	}
	ray.len = sqrtf(powf(data->player_pos.x - ray.hit_pos.x, 2)
			+ powf(data->player_pos.y - ray.hit_pos.y, 2));
	ray.hit_wall_pos = (t_iv){ray.hit_pos.x, ray.hit_pos.y - cor};
	return (static_ray_with_face_hit(ray, dir, 'y'));
}

t_ray	cast_ray(t_data *data, float r_angle)
{
	t_ray				rays[2];
	t_iv				dir;

	if (r_angle < M_PI)
		dir.y = 1;
	else
		dir.y = -1;
	if (r_angle < M_PI_2
		|| r_angle > M_PI_2 * 3)
		dir.x = 1;
	else
		dir.x = -1;
	rays[0] = static_ray_x(data, tanf(r_angle), dir, 0);
	rays[1] = static_ray_y(data, tanf(r_angle + M_PI_2), dir, 0);
	if (rays[0].len > rays[1].len)
		rays[0] = rays[1];
	rays[0].eye_len = rays[0].len * cosf(data->player_angle - r_angle);
	return (rays[0]);
}

void	ray_cast_hook(void *param)
{
	t_data *const	data = param;
	int				i;
	float			r_angle;

	i = 0;
	while (i < WIDTH)
	{
		r_angle = data->player_angle - data->fov / 2 + data->fov * i / WIDTH;
		data->rays[i] = cast_ray(data,
				r_angle - ((int)(r_angle / 2.0 / M_PI)) * 2.0 * M_PI);
		i++;
	}
}
