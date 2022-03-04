/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_box.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 17:04:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/03 18:20:25 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ml_draw_box(t_mlx_image *image, t_iv pos, t_iv size, COLOR color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			ml_draw_pixel(image, pos.x + x, pos.y + y, color);
			x++;
		}
		y++;
	}
}
