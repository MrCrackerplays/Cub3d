/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 17:44:24 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/11 13:23:03 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

UINT	ml_rgba(BYTE r, BYTE g, BYTE b, BYTE a)
{
	return (r | g << 8 | b << 16 | a << 24);
}

UINT	ml_rgb(BYTE r, BYTE g, BYTE b)
{
	return (r | g << 8 | b << 16 | 255 << 24);
}
