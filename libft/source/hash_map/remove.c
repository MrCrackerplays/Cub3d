/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 11:21:20 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:31:23 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_hash_map.h>
#include <ft_memory.h>
#include <ft_exit_error.h>
#include <ft_int_types.h>
#include <ft_cstring.h>

UINT	static_error_bs(t_ft_hash_map *hash_map, char *key)
{
	UINT	hash;

	if (!hash_map)
		ft_exit_error_d("libft: ft_hash_map_remove: got a NULL hash_map");
	if (!key)
		ft_exit_error_d("libft: ft_hash_map_remove: got a NULL key");
	hash = ft_hash_map_hash(hash_map->size, key);
	if (!hash_map->table[hash])
		ft_exit_error_d("libft: ft_hash_map_remove: key not present");
	return (hash);
}

void	*static_strip_entry(t_ft_hash_map_entry *entry)
{
	void	*item;

	item = entry->item;
	free(entry->key);
	free(entry);
	return (item);
}

void	*ft_hash_map_remove(t_ft_hash_map *hash_map, char *key)
{
	t_ft_hash_map_entry	*parse_entry;
	t_ft_hash_map_entry	*prev_entry;
	UINT				hash;

	hash = static_error_bs(hash_map, key);
	prev_entry = NULL;
	parse_entry = hash_map->table[hash];
	while (parse_entry)
	{
		if (ft_strcmp(key, parse_entry->key) == 0)
		{
			if (prev_entry)
				prev_entry->next = parse_entry->next;
			else
				hash_map->table[hash] = parse_entry->next;
			return (static_strip_entry(parse_entry));
		}
		prev_entry = parse_entry;
		parse_entry = parse_entry->next;
	}
	ft_exit_error_d("libft: ft_hash_map_remove: key not present");
	return (NULL);
}
