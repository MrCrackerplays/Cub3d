/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 14:36:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/08 20:08:31 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_get_len(t_data *data, t_sprite *sprite)
{
	sprite->dis = sqrtf(powf(sprite->pos.x - data->player_pos.x, 2)
			+ powf(sprite->pos.y - data->player_pos.y, 2));
	sprite->eye_dis = sprite->dis * cosf(data->player_angle
			- find_angle(data->player_pos, sprite->pos));
}

static COLOR	get_color_at(t_mlx_image *img, int x, int y)
{
	uint8_t		*pixel;

	pixel = img->pixels + (y * (4 * img->width)) + (4 * x);
	return (ml_rgba(pixel[0], pixel[1], pixel[2], pixel[3]));
}

static void	static_draw_line(t_data *data, t_sprite *sprite, float i, int pos)
{
	COLOR	c;
	int		j;
	int		y;

	if (sprite->size_y > HEIGHT)
		j = fmaxf((sprite->size_y - HEIGHT) / 2 - data->player_ud_angle, 0);
	else
		j = 0;
	y = data->player_ud_angle + j + (HEIGHT - sprite->size_y) / 2;
	while (j < sprite->size_y && y < HEIGHT)
	{
		c = get_color_at(sprite->image, i / sprite->size_x
				* sprite->image->width,
				j / sprite->size_y * sprite->image->height);
		if (ml_color_a(c) > 128)
			ml_draw_pixel(data->screen, pos, y, c);
		j++;
		y = data->player_ud_angle + j + (HEIGHT - sprite->size_y) / 2;
	}
	if (true || i || pos || data || sprite || j)
		return ;
}

static void	static_draw_sprite(t_data *data, t_sprite *sprite)
{
	float	r_angle;
	float	p_angle;
	int		pos;
	float	i;

	sprite->image = data->sprite[((int)(data->game_time / .5)) % 3];
	sprite->size_x = HEIGHT / sprite->dis;
	sprite->size_y = HEIGHT / sprite->eye_dis;
	p_angle = data->player_angle - 2.0 * M_PI;
	if (data->player_pos.x < sprite->pos.x && p_angle > M_PI)
		p_angle -= 2.0 * M_PI;
	i = 0;
	while (i < sprite->size_x)
	{
		r_angle = find_angle(data->player_pos, sprite->pos);
		if (data->player_pos.x < sprite->pos.x && r_angle > M_PI)
			r_angle -= 2.0 * M_PI;
		pos = (int)((r_angle - (p_angle - data->fov / 2)) / data->fov * WIDTH);
		pos = pos - sprite->size_x / 2.0 + i;
		if ((pos >= 0 && pos < WIDTH) && data->rays[pos].len > sprite->dis)
			static_draw_line(data, sprite, i, pos);
		i++;
	}
}

void	sprite_hook(t_data *data)
{
	t_ft_list_node		*parse;
	void				*temp;

	parse = data->sprites->first;
	if (!parse)
		return ;
	static_get_len(data, parse->item);
	while (parse->next)
	{
		static_get_len(data, parse->next->item);
		if (((t_sprite *)parse->item)->dis < ((t_sprite *)parse->next->item)
			->dis)
		{
			static_draw_sprite(data, parse->next->item);
			temp = parse->item;
			parse->item = parse->next->item;
			parse->next->item = temp;
		}
		else
			static_draw_sprite(data, parse->item);
		parse = parse->next;
	}
	static_draw_sprite(data, data->sprites->last->item);
}
