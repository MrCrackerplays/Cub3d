/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 11:21:20 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:29:24 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hash_map.h>
#include <ft_memory.h>
#include <ft_exit_error.h>
#include <ft_int_types.h>
#include <ft_cstring.h>

void	*ft_hash_map_get(t_ft_hash_map *hash_map, char *key)
{
	t_ft_hash_map_entry	*parse_entry;
	UINT				hash;

	if (!hash_map)
		ft_exit_error_d("libft: ft_hash_map_get: got a NULL hash_map");
	if (!key)
		ft_exit_error_d("libft: ft_hash_map_get: got a NULL key");
	hash = ft_hash_map_hash(hash_map->size, key);
	if (!hash_map->table[hash])
		ft_exit_error_d("libft: ft_hash_map_get: key not present");
	parse_entry = hash_map->table[hash];
	while (parse_entry)
	{
		if (ft_strcmp(key, parse_entry->key) == 0)
			return (parse_entry->item);
		parse_entry = parse_entry->next;
	}
	ft_exit_error_d("libft: ft_hash_map_get: key not present");
	return (NULL);
}
