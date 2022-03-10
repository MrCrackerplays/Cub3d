/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_angle_fix.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 16:08:33 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/10 14:40:55 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	ray_angle_fix(t_data *data, int i)
{
	float	screen_halflen;
	float	seg_len;

	screen_halflen = tanf(data->fov / 2);
	seg_len = screen_halflen / (WIDTH / 2);
	return (atanf(seg_len * i - screen_halflen));
}
