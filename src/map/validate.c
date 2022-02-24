/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 17:53:15 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/24 18:27:39 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// static void	static_test_middle(t_data *data)
// {
// 	t_iv	pos;

// 	pos.y = 1;
// 	while (pos.y < data->map->len - 1)
// 	{
// 		pos.x = 1;
// 		while (map_get_at(data->map, pos.x, pos.y) == ' ')
// 			pos.x++;
// 		while (pos.x < ((t_ft_string *)ft_list_item_at(data->map, pos.y))->len)
// 		{
			
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// }

void	validate_map(t_data *data)
{
	if (data)
		return ;
	//static_test_middle(data);
}
