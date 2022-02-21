/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 17:04:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/21 22:17:49 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ml_draw_line(t_mlx_image *image, t_iv p1, t_iv p2, COLOR color)
{
	const float	xlen = p2.x - p1.x;
	const float	ylen = p2.y - p1.y;
	const float	target = fmax(abs(xlen), abs(ylen));
	float		i;

	if (target > WIDTH * HEIGHT)
		return ;
	if (target == 0)
		ml_draw_pixel(image, p1.x, p1.y, color);
	i = 0;
	while (i < target)
	{
		ml_draw_pixel(image,
			p1.x + (int)(xlen * i / target),
			p1.y + (int)(ylen * i / target),
			color);
		i++;
	}
}
