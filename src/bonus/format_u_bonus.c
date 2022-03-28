/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_u_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:10:47 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/28 13:56:09 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

t_ft_hash_map	*format_init(t_data *data)
{
	t_ft_hash_map	*texs;

	texs = ft_hash_map_new(100);
	ft_hash_map_set(texs, "NO ", &data->north);
	ft_hash_map_set(texs, "SO ", &data->south);
	ft_hash_map_set(texs, "EA ", &data->east);
	ft_hash_map_set(texs, "WE ", &data->west);
	ft_hash_map_set(texs, "D0 ", &data->door[0]);
	ft_hash_map_set(texs, "D1 ", &data->door[1]);
	ft_hash_map_set(texs, "D2 ", &data->door[2]);
	ft_hash_map_set(texs, "S0 ", &data->sprite[0]);
	ft_hash_map_set(texs, "S1 ", &data->sprite[1]);
	ft_hash_map_set(texs, "S2 ", &data->sprite[2]);
	ft_hash_map_set(texs, "CI ", &data->ceil_img);
	ft_hash_map_set(texs, "FI ", &data->floor_img);
	return (texs);
}

void	format_check(t_data *data, bool r, bool f)
{
	if (r || f || !data->north || !data->south || !data->west || !data->east
		|| !data->door[0] || !data->door[1] || !data->door[2]
		|| !data->sprite[0] || !data->sprite[1] || !data->sprite[2]
		|| !data->ceil_img || !data->floor_img)
		ft_exit_error("Invalid map.1");
}
