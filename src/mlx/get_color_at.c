/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color_at.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 12:25:22 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/12 20:05:19 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

COLOR	ml_color_at(t_mlx_image *img, UINT x, UINT y)
{
	COLOR	*pixel;

	if (x >= img->width || y >= img->height)
		return (0xffFF00FF);
	pixel = (COLOR *)(img->pixels + (y * (4 * img->width)) + (4 * x));
	return (*pixel);
}
