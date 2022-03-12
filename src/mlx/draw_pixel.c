/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_pixel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 19:29:36 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/12 16:53:30 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ml_draw_pixel(t_mlx_image *img, UINT x, UINT y, COLOR color)
{
	COLOR	*pixel;

	if (x >= img->width || y >= img->height)
		return ;
	pixel = (COLOR *)(&img->pixels[(y * img->width + x) * sizeof(int32_t)]);
	*pixel = color;
}
