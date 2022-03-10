/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 17:44:24 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/10 14:53:24 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

UINT	ml_rgba(BYTE r, BYTE g, BYTE b, BYTE a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

UINT	ml_rgb(BYTE r, BYTE g, BYTE b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}
