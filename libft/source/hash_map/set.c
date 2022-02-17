/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 11:21:20 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:31:31 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hash_map.h>
#include <ft_memory.h>
#include <ft_exit_error.h>
#include <ft_int_types.h>
#include <ft_cstring.h>

void	ft_hash_map_set(t_ft_hash_map *hash_map, char *key, void *item)
{
	t_ft_hash_map_entry	*entry;
	t_ft_hash_map_entry	*parse_entry;
	UINT				hash;

	if (!hash_map)
		ft_exit_error_d("libft: ft_hash_map_set: got a NULL hash_map");
	if (!key)
		ft_exit_error_d("libft: ft_hash_map_set: got a NULL key");
	entry = ft_malloc_e(sizeof(t_ft_hash_map_entry), "libft: ft_hash_map_set");
	entry->key = ft_strdup(key);
	entry->item = item;
	entry->next = NULL;
	hash = ft_hash_map_hash(hash_map->size, key);
	if (!hash_map->table[hash])
		hash_map->table[hash] = entry;
	else
	{
		parse_entry = hash_map->table[hash];
		while (parse_entry->next)
			parse_entry = parse_entry->next;
		parse_entry->next = entry;
	}
}
