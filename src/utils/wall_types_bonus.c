/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_types_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 17:20:18 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 17:24:45 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	is_wall(char c)
{
	if (c == '1' || c == 'D')
		return (true);
	return (false);
}
