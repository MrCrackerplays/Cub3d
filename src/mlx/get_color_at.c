/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color_at.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 12:25:22 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/11 13:33:43 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

COLOR	get_color_at(t_mlx_image *img, size_t x, size_t y)
{
	COLOR	*pixel;

	pixel = img->pixels + (y * (4 * img->width)) + (4 * x);
	return (*pixel);
}
