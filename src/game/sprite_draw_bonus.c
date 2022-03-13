/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_draw_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 19:21:56 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/13 18:41:40 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static COLOR	static_get_color_at(
	t_sprite *sprite, t_iv vecs[2], int ss_x)
{
	const t_iv	pos = vecs[0];
	const t_iv	sprite_s = vecs[1];
	COLOR		c;

	c = ml_color_at(sprite->image,
			(pos.x + sprite_s.x / 2 - ss_x)
			* sprite->image->width / sprite_s.x,
			(pos.y + (sprite_s.y - HEIGHT) / 2)
			* sprite->image->height / sprite_s.y);
	return (ml_color_darken(c, 1.0 / fmaxf(1.0, 0.25 * (sprite->dis))));
}

static void	draw_sprite2(
	t_data *data, t_sprite *sprite, t_iv vecs[3], float nums[2])
{
	const int	ss_x = nums[0];
	const float	trans_y = nums[1];
	COLOR		c;
	t_iv		pos;

	pos.x = vecs[0].x;
	while (pos.x < vecs[0].y)
	{
		if ((trans_y > 0 && trans_y < data->rays[pos.x].eye_len))
		{
			pos.y = vecs[1].x;
			while (pos.y < vecs[1].y)
			{
				c = static_get_color_at(
						sprite, (t_iv [2]){pos, vecs[2]}, ss_x);
				if (((BYTE *)&c)[3] > 128)
					ml_draw_pixel(data->screen,
						pos.x, pos.y + data->player_ud_angle,
						c);
				pos.y++;
			}
		}
		pos.x++;
	}
}

static t_iv	get_x_limit(t_iv sprite_s, int ss_x)
{
	t_iv	x_limit;

	x_limit.x = -sprite_s.x / 2 + ss_x;
	if (x_limit.x < 0)
		x_limit.x = 0;
	x_limit.y = sprite_s.x / 2 + ss_x;
	if (x_limit.y > WIDTH)
		x_limit.y = WIDTH;
	return (x_limit);
}

static t_iv	get_y_limit(t_data *data, t_iv sprite_s)
{
	t_iv	y_limit;

	y_limit.x = -sprite_s.y / 2 + HEIGHT / 2;
	if (y_limit.x < 0 - data->player_ud_angle)
		y_limit.x = 0 - data->player_ud_angle;
	y_limit.y = sprite_s.y / 2 + HEIGHT / 2;
	if (y_limit.y >= HEIGHT - data->player_ud_angle)
		y_limit.y = HEIGHT - 1 - data->player_ud_angle;
	if (data)
		return (y_limit);
	return (y_limit);
}

void	draw_sprite(t_data *data, t_sprite *sprite)
{
	float	trans_y;
	int		ss_x;
	t_iv	sprite_s;

	if (sprite->eye_dis < .1)
		return ;
	trans_y = 1.0 / (data->plane.x * data->dir.y - data->dir.x * data->plane.y)
		* (-data->plane.y * (sprite->pos.x - data->player_pos.x) + data->plane.x
			* (sprite->pos.y - data->player_pos.y));
	ss_x = (int)((WIDTH / 2) * (1
				+ (1.0 / (data->plane.x * data->dir.y - data->dir.x
						* data->plane.y) * (data->dir.y * (sprite->pos.x
							- data->player_pos.x) - data->dir.x
						* (sprite->pos.y - data->player_pos.y))) / trans_y));
	sprite_s.y = abs((int)(HEIGHT / (trans_y)));
	sprite_s.x = sprite_s.y;
	draw_sprite2(data, sprite, (t_iv [3]){
		get_x_limit(sprite_s, ss_x), get_y_limit(data, sprite_s),
		sprite_s}, (float [2]){ss_x, trans_y});
}
