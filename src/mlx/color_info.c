/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_info.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 17:44:24 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 15:18:32 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

BYTE	ml_color_r(UINT rgba)
{
	return (rgba >> 24);
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
	return (rgba);
}
