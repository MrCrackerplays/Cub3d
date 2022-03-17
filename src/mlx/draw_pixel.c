/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_pixel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 19:29:36 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/17 16:24:39 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ml_draw_pixel(t_mlx_image *img, UINT x, UINT y, COLOR color)
{
	COLOR	*pixel;

	if (x >= img->width || y >= img->height)
		return ;
	pixel = (COLOR *)&img->pixels[(x + y * img->width) * sizeof(COLOR)];
	*pixel = color;
}

void	ml_draw_pixel_s(t_data *data, t_mlx_image *img, t_iv pos, COLOR color)
{
	COLOR	*pixel;

	if ((UINT)pos.x >= img->width || (UINT)pos.y >= img->height)
		return ;
	if (data->bitmap[pos.x][pos.y] == data->bitmode)
		return ;
	data->bitmap[pos.x][pos.y] = data->bitmode;
	pixel = (COLOR *)&img->pixels[(pos.x + pos.y * img->width) * sizeof(COLOR)];
	*pixel = color;
}
