/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 20:00:39 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:29:05 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_hash_map.h>
#include <ft_exit_error.h>

static void	static_free_entry(t_ft_hash_map_entry *entry)
{
	if (!entry)
		return ;
	if (entry->next)
		static_free_entry(entry->next);
	free(entry->key);
	free(entry);
}

void	ft_hash_map_free(t_ft_hash_map *hash_map)
{
	UINT	index;

	if (!hash_map)
		ft_exit_error_d("libft: ft_hash_map_free: got a NULL hash_map");
	index = 0;
	while (index < hash_map->size)
	{
		if (hash_map->table[index])
			static_free_entry(hash_map->table[index]);
		index++;
	}
	free(hash_map->table);
	free(hash_map);
}

static void	static_free_entry_all(t_ft_hash_map_entry *entry,
	void (*del)(void *item))
{
	if (!entry)
		return ;
	if (entry->next)
		static_free_entry(entry->next);
	(*del)(entry->item);
	free(entry->key);
	free(entry);
}

void	ft_hash_map_free_all(t_ft_hash_map *hash_map,
	void (*del)(void *item))
{
	UINT	index;

	if (!hash_map)
		ft_exit_error_d("libft: ft_hash_map_free_all: got a NULL hash_map");
	if (!del)
		ft_exit_error_d("libft: ft_hash_map_free_all: got a NULL function");
	index = 0;
	while (index < hash_map->size)
	{
		if (hash_map->table[index])
			static_free_entry_all(hash_map->table[index], del);
		index++;
	}
	free(hash_map->table);
	free(hash_map);
}
