/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 11:15:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:30:13 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hash_map.h>
#include <ft_memory.h>
#include <ft_exit_error.h>
#include <ft_int_types.h>

t_ft_hash_map	*ft_hash_map_new(UINT size)
{
	t_ft_hash_map	*hash_map;
	UINT			index;

	hash_map = ft_malloc_e(sizeof(t_ft_hash_map), "libft: ft_hash_map_new");
	hash_map->table = ft_malloc_e(sizeof(t_ft_hash_map_entry *) * size,
			"libft: ft_hash_map_new");
	hash_map->size = size;
	index = 0;
	while (index < size)
	{
		hash_map->table[index] = NULL;
		index++;
	}
	return (hash_map);
}
