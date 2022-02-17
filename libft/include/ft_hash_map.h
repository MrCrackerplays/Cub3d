/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash_map.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 10:57:41 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/07 19:23:36 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_MAP_H
# define FT_HASH_MAP_H

# include <ft_int_types.h>

typedef struct s_ft_hash_map_entry {
	char						*key;
	void						*item;
	struct s_ft_hash_map_entry	*next;
}	t_ft_hash_map_entry;

typedef struct s_ft_hash_map {
	UINT				size;
	t_ft_hash_map_entry	**table;
}	t_ft_hash_map;

t_ft_hash_map	*ft_hash_map_new(UINT size);
void			ft_hash_map_free(t_ft_hash_map *hash_map);
void			ft_hash_map_free_all(t_ft_hash_map *hash_map,
					void (*del)(void *));

UINT			ft_hash_map_hash(UINT size, char *key);

void			ft_hash_map_set(t_ft_hash_map *hash_map, char *key,
					void *item);
void			*ft_hash_map_get(t_ft_hash_map *hash_map, char *key);
void			*ft_hash_map_remove(t_ft_hash_map *hash_map, char *key);

BOOL			ft_hash_map_has_key(t_ft_hash_map *hash_map, char *key);

#endif
