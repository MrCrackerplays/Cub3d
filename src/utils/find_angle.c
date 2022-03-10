/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_angle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 16:26:50 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/10 14:40:26 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	find_angle(t_fv p1, t_fv p2)
{
	float	angle;

	angle = atanf((p2.y - p1.y) / (p2.x - p1.x));
	if (p2.x - p1.x < 0)
		angle += M_PI;
	if (angle < 0)
		angle += 2.0 * M_PI;
	return (angle);
}
