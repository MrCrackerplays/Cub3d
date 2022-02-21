/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_casting.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 20:39:44 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/21 22:35:04 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	map_get_at(t_ft_list *map, UINT x, UINT y)
{
	t_ft_string	*line;

	if (x < 0 || y < 0)
		return ('\0');
	if (y >= map->len)
		return ('\0');
	line = ft_list_item_at(map, y);
	if (x >= line->len)
		return ('\0');
	return (line->text[x]);
}

static int	static_corect(int n)
{
	if (n < 0)
		return (n + 1);
	return (n);
}

static t_ray
	static_ray_x(t_data *data, float r_angle, t_iv dir)
{
	t_ray		ray;
	const float	tan_res = tanf(r_angle);
	int			i;
	int			cor;

	cor = 0;
	if (dir.x == -1)
		cor = 1;
	ray.hit_pos.x = (int)data->player_pos.x + static_corect(dir.x);
	ray.hit_pos.y = (float)(data->player_pos.x - (int)data->player_pos.x);
	if (dir.x == 1)
		ray.hit_pos.y = (1 - ray.hit_pos.y);
	ray.hit_pos.y = data->player_pos.y + (ray.hit_pos.y * tan_res * dir.x);
	i = 0;
	while (i < data->ray_depth
		&& map_get_at(data->map, ray.hit_pos.x - cor, ray.hit_pos.y) != '1')
	{
		ray.hit_pos.x += dir.x;
		ray.hit_pos.y += (tan_res * dir.x);
		i++;
	}
	ray.len = sqrtf(powf(data->player_pos.x - ray.hit_pos.x, 2)
			+ powf(data->player_pos.y - ray.hit_pos.y, 2));
	return (ray);
}

static t_ray
	static_ray_y(t_data *data, float r_angle, t_iv dir)
{
	t_ray		ray;
	const float	tan_res = tanf(r_angle);
	int			i;
	int			cor;

	cor = 0;
	if (dir.y == -1)
		cor = 1;
	ray.hit_pos = (t_fv){0, 0};
	ray.hit_pos.y = (int)data->player_pos.y + static_corect(dir.y);
	ray.hit_pos.x = data->player_pos.y - (int)data->player_pos.y;
	if (dir.y == 1)
		ray.hit_pos.x = 1 - ray.hit_pos.x;
	ray.hit_pos.x = data->player_pos.x + ray.hit_pos.x * tan_res * (-dir.y);
	i = 0;
	while (i < data->ray_depth
		&& map_get_at(data->map, ray.hit_pos.x, ray.hit_pos.y - cor) != '1')
	{
		ray.hit_pos.y += dir.y;
		ray.hit_pos.x += (tan_res * (-dir.y));
		i++;
	}
	ray.len = sqrtf(powf(data->player_pos.x - ray.hit_pos.x, 2)
			+ powf(data->player_pos.y - ray.hit_pos.y, 2));
	return (ray);
}

t_ray	cast_ray(t_data *data, float r_angle)
{
	t_ray		rays[2];
	t_iv		dir;

	if (r_angle < M_PI)
		dir.y = 1;
	else
		dir.y = -1;
	if (r_angle < M_PI_2
		|| r_angle > M_PI_2 * 3)
		dir.x = 1;
	else
		dir.x = -1;
	rays[0] = static_ray_x(data, r_angle, dir);
	rays[1] = static_ray_y(data, r_angle + M_PI_2, dir);
	if (rays[0].len < rays[1].len)
		return (rays[0]);
	return (rays[1]);
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
				r_angle - (int)(r_angle / 2.0 / M_PI) *2.0 * M_PI);
		i++;
	}
}
