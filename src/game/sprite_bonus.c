/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 14:36:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/17 16:36:38 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "sprite.h"

static void	static_get_len_and_load_sprite(t_data *data, t_sprite *sprite)
{
	sprite->image = data->sprite[((int)(data->game_time / .5)) % 3];
	sprite->dis = sqrtf(powf(sprite->pos.x - data->player_pos.x, 2)
			+ powf(sprite->pos.y - data->player_pos.y, 2));
	sprite->eye_dis = sprite->dis * cosf(data->player_angle
			- find_angle(data->player_pos, sprite->pos));
}

void	sprite_hook(t_data *data)
{
	t_ft_list_node		*parse;
	void				*temp;

	parse = data->sprites->first;
	if (!parse)
		return ;
	static_get_len_and_load_sprite(data, parse->item);
	while (parse->next)
	{
		static_get_len_and_load_sprite(data, parse->next->item);
		if (((t_sprite *)parse->item)->dis < ((t_sprite *)parse->next->item)
			->dis)
		{
			temp = parse->item;
			parse->item = parse->next->item;
			parse->next->item = temp;
		}
		parse = parse->next;
	}
	while (parse)
	{
		draw_sprite(data, parse->item);
		parse = parse->prev;
	}
}
