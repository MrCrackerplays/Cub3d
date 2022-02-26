/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 18:18:03 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/26 18:01:14 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* BONUS */
static void	static_player_door(t_data *const data)
{
	t_fv			move_vec;
	static bool		last;

	if (!mlx_is_key_down(data->mlx, MLX_KEY_E) || last
		|| map_get_at(data->map, data->player_pos.x, data->player_pos.y) == 'O')
	{
		last = mlx_is_key_down(data->mlx, MLX_KEY_E);
		return ;
	}
	move_vec.x = data->player_pos.x + cosf(data->player_angle);
	move_vec.y = data->player_pos.y + sinf(data->player_angle);
	if (map_get_at(data->map, move_vec.x, move_vec.y) == 'D')
		((t_ft_string *)ft_list_item_at(
				data->map, move_vec.y))->text[(int)move_vec.x]
			= 'O';
	else if (map_get_at(data->map, move_vec.x, move_vec.y) == 'O')
		((t_ft_string *)ft_list_item_at(
				data->map, move_vec.y))->text[(int)move_vec.x]
			= 'D';
	last = mlx_is_key_down(data->mlx, MLX_KEY_E);
}

/* BONUS */
static void	static_player_rotation_mouse(t_data *const data)
{
	int	mouse_x;
	int	mouse_y;

	mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
	if (mouse_x < 0 || mouse_x > WIDTH || mouse_y < 0 || mouse_y > HEIGHT)
		return ;
	mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
	data->player_angle += ((float)(mouse_x - WIDTH / 2)) * .0025;
	if (data->player_angle >= 4.0 * M_PI)
			data->player_angle -= 2.0 * M_PI;
	else if (data->player_angle < 2.0 * M_PI)
			data->player_angle += 2.0 * M_PI;
}

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
	static_player_rotation_mouse(data);
}

static void	static_move_forward(t_data *const data, float angle)
{
	t_fv	move_vec;
	float	move_dist;

	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		move_dist = MOVE_SPEED * 2;
	else
		move_dist = MOVE_SPEED;
	if (cast_ray(data, angle).len < move_dist)
		return ;
	move_vec.x = data->player_pos.x + move_dist * cosf(angle);
	move_vec.y = data->player_pos.y + move_dist * sinf(angle);
	if (!is_wall(map_get_at(data->map, move_vec.x, move_vec.y)))
	data->player_pos = move_vec;
}

void	player_movement_hook(void *param)
{
	t_data *const	data = param;
	float			angle;
	t_fv			move_vec;

	static_player_rotation(data);
	static_player_door(data);
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
	static_move_forward(data, angle);
}
