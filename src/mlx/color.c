/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 17:44:24 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/13 18:27:25 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

COLOR	ml_rgba(BYTE r, BYTE g, BYTE b, BYTE a)
{
	return (r | g << 8 | b << 16 | a << 24);
}

COLOR	ml_rgb(BYTE r, BYTE g, BYTE b)
{
	return (r | g << 8 | b << 16 | 255 << 24);
}

COLOR	ml_color_darken(COLOR c, float darkness_mod)
{
	BYTE	*ptr;

	ptr = (BYTE *)&c;
	ptr[0] *= darkness_mod;
	ptr[1] *= darkness_mod;
	ptr[2] *= darkness_mod;
	return (c);
}
