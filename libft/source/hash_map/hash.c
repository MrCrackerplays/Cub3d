/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 11:23:49 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:30:04 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hash_map.h>
#include <ft_memory.h>
#include <ft_exit_error.h>
#include <ft_int_types.h>

UINT	ft_hash_map_hash(UINT size, char *key)
{
	UINT	index;
	UINT	hash;

	if (!key)
		ft_exit_error_d("libft: ft_hash_map_hash: got a NULL key");
	index = 0;
	hash = 0;
	while (key[index])
	{
		hash = hash * 37 + key[index];
		index++;
	}
	return (hash % size);
}
