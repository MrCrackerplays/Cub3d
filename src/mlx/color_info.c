/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_info.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 17:44:24 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/17 16:13:59 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

//return (a << 24 | g << 16 | b << 8 | r);

BYTE	ml_color_r(UINT rgba)
{
	return (rgba);
}

BYTE	ml_color_g(UINT rgba)
{
	return (rgba >> 16);
}

BYTE	ml_color_b(UINT rgba)
{
	return (rgba >> 8);
}

BYTE	ml_color_a(UINT rgba)
{
	return (rgba >> 24);
}
