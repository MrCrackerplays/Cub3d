/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 15:54:34 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/17 17:08:44 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <libft.h>

# define COLOR unsigned int

COLOR	ml_rgba(BYTE r, BYTE g, BYTE b, BYTE a);
COLOR	ml_rgb(BYTE r, BYTE g, BYTE b);
BYTE	ml_color_r(COLOR rgba);
BYTE	ml_color_g(COLOR rgba);
BYTE	ml_color_b(COLOR rgba);
BYTE	ml_color_a(COLOR rgba);

double	ml_tan(double degree);

#endif
