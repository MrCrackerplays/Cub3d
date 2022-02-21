/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 18:18:03 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/21 21:45:09 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	static_player_rotation(t_data *const data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->player_angle += ROT_SPEED;
		if (data->player_angle >= 4.0 * M_PI)
			data->player_angle -= 2.0 * M_PI;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player_angle -= ROT_SPEED;
		if (data->player_angle < 2.0 * M_PI)
			data->player_angle += 2.0 * M_PI;
	}
}

void	player_movement_hook(void *param)
{
	t_data *const	data = param;
	float			angle;
	t_fv			move_vec;

	static_player_rotation(data);
	move_vec = (t_fv){0, 0};
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_vec.x++;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_vec.x--;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_vec.y--;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_vec.y++;
	if (!(move_vec.x + 2 * move_vec.y))
		return ;
	angle = atanf(move_vec.y / move_vec.x) + data->player_angle;
	if (move_vec.x < 0)
		angle += M_PI;
	data->player_pos.x += MOVE_SPEED * cosf(angle);
	data->player_pos.y += MOVE_SPEED * sinf(angle);
}
