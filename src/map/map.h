/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:13:38 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/18 15:26:54 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <cub3d.h>

t_ft_hash_map	*format_init(t_data *data);
void			format_check(t_data *data, bool r, bool f);

bool			is_in_wall_and_set_player(t_data *data, t_iv pos, char c);

#endif
