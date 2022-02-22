/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_pixel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 19:29:36 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 18:01:22 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ml_draw_pixel(t_mlx_image *img, int x, int y, COLOR color)
{
	if (x < 0 || y < 0 || x > img->width || y > img->height)
		return ;
	mlx_putpixel(img, x, y, color);
}
