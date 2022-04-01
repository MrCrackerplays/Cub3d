/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_u.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:10:51 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/04/01 14:06:13 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_ft_hash_map	*format_init(t_data *data)
{
	t_ft_hash_map	*texs;

	texs = ft_hash_map_new(100);
	ft_hash_map_set(texs, "NO ", &data->north);
	ft_hash_map_set(texs, "SO ", &data->south);
	ft_hash_map_set(texs, "EA ", &data->east);
	ft_hash_map_set(texs, "WE ", &data->west);
	return (texs);
}

void	format_check(t_data *data, bool r, bool f)
{
	if (!r || !f || !data->north || !data->south || !data->west || !data->east)
		ft_exit_error("Invalid map.");
}
