/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mirror_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 13:45:55 by pdruart       #+#    #+#                 */
/*   Updated: 2022/03/17 16:30:40 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static float	static_new_angle(t_ray ray, float r_angle)
{
	if (ray.wall_face == 'n')
		r_angle = (2 * M_PI) - fmodf(r_angle, M_PI);
	else if (ray.wall_face == 's')
		r_angle = M_PI - fmodf(r_angle, M_PI);
	else if (ray.wall_face == 'e')
		r_angle = (2.5 * M_PI) - fmodf(r_angle - M_PI_2, M_PI);
	else if (ray.wall_face == 'w')
	{
		if (r_angle <= M_PI_2)
			r_angle = (1.5 * M_PI) - fmodf(r_angle + M_PI_2, M_PI);
		if (r_angle >= 3 * M_PI_2)
			r_angle = (1.5 * M_PI) - fmodf(r_angle - M_PI_2, M_PI);
	}
	r_angle = fmodf(r_angle, 2 * M_PI);
	return (r_angle);
}

t_ray	mirror_hit(t_data *data, float r_angle, t_ray ray, float mirror_len)
{
	t_ray	local;

	if (ray.len >= data->ray_depth)
		return (ray);
	r_angle = static_new_angle(ray, r_angle);
	local = cast_ray(data, r_angle, ray.hit_pos, mirror_len - ray.len);
	local.hit_pos_i = ray.hit_pos_i;
	local.len += ray.len;
	local.eye_len = local.len;
	if (local.len <= data->ray_depth)
		return (local);
	ray.wall_type = '0';
	ray.wall_face = '0';
	return (ray);
}
