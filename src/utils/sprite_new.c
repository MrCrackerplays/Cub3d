/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 18:23:25 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/08 18:25:07 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_sprite	*sprite_new(float x, float y)
{
	t_sprite	*sprite;

	sprite = ft_malloc(sizeof(t_sprite));
	sprite->pos = (t_fv){x, y};
	return (sprite);
}
