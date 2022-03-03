/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   has_key.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 15:55:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/03 15:58:11 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_int_types.h>
#include <ft_hash_map.h>
#include <ft_exit_error.h>

BOOL			ft_hash_map_has_key(t_ft_hash_map *hash_map, char *key)
{
    UINT				hash;

	if (!hash_map)
		ft_exit_error_d("libft: ft_hash_map_has_key: got a NULL hash_map");
	if (!key)
		ft_exit_error_d("libft: ft_hash_map_has_key: got a NULL key");
	hash = ft_hash_map_hash(hash_map->size, key);
	if (!hash_map->table[hash])
		return FALSE;
    return TRUE;
}
