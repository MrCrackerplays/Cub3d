/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:53:15 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/18 15:26:17 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	is_in_wall_and_set_player(t_data *data, t_iv pos, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (data->player_pos.x != 0)
			ft_exit_error("Reassigning player position.");
		data->player_pos = (t_fv){pos.x + .5, pos.y + .5};
		if (c == 'N')
			data->player_angle += M_PI + M_PI / 2;
		else if (c == 'S')
			data->player_angle += M_PI / 2;
		else if (c == 'W')
			data->player_angle += M_PI;
		return (true);
	}	
	return (c == '0');
}
