/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_angle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 16:26:50 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 17:19:43 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// angle = atanf(move_vec.y / move_vec.x) + data->player_angle;
// if (move_vec.x < 0)
// 	angle += M_PI;

float	find_angle(t_fv p1, t_fv p2)
{
	float	angle;

	angle = atanf((p2.y - p1.y) / (p2.x - p1.x));
	if (p2.x - p1.x < 0)
		angle += M_PI;
	return (angle);
}
