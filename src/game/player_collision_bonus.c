/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_collision_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 15:38:43 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/16 15:52:34 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	player_collision_correction(t_data *data)
{
	float	ray_len;

	ray_len = cast_ray(data, 0, data->player_pos, 0).len;
	if (ray_len < WALL_DIST)
		data->player_pos.x -= (WALL_DIST - ray_len);
	ray_len = cast_ray(data, M_PI, data->player_pos, 0).len;
	if (ray_len < WALL_DIST)
		data->player_pos.x += (WALL_DIST - ray_len);
	ray_len = cast_ray(data, M_PI_2, data->player_pos, 0).len;
	if (ray_len < WALL_DIST)
		data->player_pos.y -= (WALL_DIST - ray_len);
	ray_len = cast_ray(data, 3 * M_PI_2, data->player_pos, 0).len;
	if (ray_len < WALL_DIST)
		data->player_pos.y += (WALL_DIST - ray_len);
}
