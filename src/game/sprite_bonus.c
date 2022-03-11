/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 14:36:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/11 13:34:39 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_draw_line(t_data *data, t_sprite *sprite, float i, int pos)
{
	COLOR	c;
	int		j;
	int		y;
	float	darkness_mod;

	if (sprite->size_y > HEIGHT)
		j = fmaxf((sprite->size_y - HEIGHT) / 2 - data->player_ud_angle, 0);
	else
		j = 0;
	y = data->player_ud_angle + j + (HEIGHT - sprite->size_y) / 2;
	darkness_mod = 1.0 / fminf(15.0, fmaxf(1.0, 0.25 * (sprite->dis)));
	while (j < sprite->size_y && y < HEIGHT)
	{
		c = get_color_at(sprite->image, i / sprite->size_x
				* sprite->image->width,
				j / sprite->size_y * sprite->image->height);
		if (ml_color_a(c) > 128)
			ml_draw_pixel(data->screen, pos, y, ml_rgba(ml_color_r(c) \
			* darkness_mod, ml_color_g(c) * darkness_mod, ml_color_b(c) \
			* darkness_mod, ml_color_a(c)));
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
	sprite->size_x = HEIGHT / ((sprite->eye_dis * .5 + sprite->dis) / 1.5);
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
		pos = (r_angle - (p_angle - data->fov / 2)) / data->fov * WIDTH;
		pos = pos - sprite->size_x / 2.0 + i;
		if ((pos >= 0 && pos < WIDTH) && data->rays[pos].len > sprite->dis)
			static_draw_line(data, sprite, i, pos);
		i++;
	}
}

// static void	static_draw_sprite(t_data *data, t_sprite *sprite)
// {
// 	/* Random bs */

// 	double dirX = cos(data->player_angle);
// 	double dirY = sin(data->player_angle);

// 	system("clear");
// 	printf("angle %f\nx cos %f\ny sin %f\n", data->player_angle - 2*M_PI, dirX, dirY);

// 	double planeX = 1;
// 	double planeY = 1;

// 	/* End */

// 	double spriteX = sprite->pos.x - data->player_pos.x;
// 	double spriteY = sprite->pos.y - data->player_pos.y;

// 	//transform sprite with the inverse camera matrix
// 	// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
// 	// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
// 	// [ planeY   dirY ]                                          [ -planeY  planeX ]

// 	double invDet = 1.0 / (planeX * dirY - dirX * planeY); //required for correct matrix multiplication

// 	double transformX = invDet * (dirY * spriteX - dirX * spriteY);
// 	double transformY = invDet * (-planeY * spriteX + planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

// 	int spriteScreenX = (int)((WIDTH / 2) * (1 + transformX / transformY));

// 	//calculate height of the sprite on screen
// 	int spriteHeight = abs((int)(HEIGHT / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
// 	//calculate lowest and highest pixel to fill in current stripe
// 	int drawStartY = -spriteHeight / 2 + HEIGHT / 2;
// 	if(drawStartY < 0) drawStartY = 0;
// 	int drawEndY = spriteHeight / 2 + HEIGHT / 2;
// 	if(drawEndY >= HEIGHT) drawEndY = HEIGHT - 1;

// 	//calculate width of the sprite
// 	int spriteWidth = abs( (int) (HEIGHT / (transformY)));
// 	int drawStartX = -spriteWidth / 2 + spriteScreenX;
// 	if(drawStartX < 0) drawStartX = 0;
// 	int drawEndX = spriteWidth / 2 + spriteScreenX;
// 	if(drawEndX >= WIDTH) drawEndX = WIDTH - 1;

// 	for(int stripe = drawStartX; stripe < drawEndX; stripe++)
// 		for(int y = drawStartY; y < drawEndY; y++)
// 			ml_draw_pixel(data->screen, stripe, y + data->player_ud_angle, 0xffFFffFF);
// }

static void	static_get_len(t_data *data, t_sprite *sprite)
{
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
