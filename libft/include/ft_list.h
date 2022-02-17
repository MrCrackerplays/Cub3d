/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 18:11:37 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/07 19:27:53 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <ft_int_types.h>

typedef struct s_ft_list_node
{
	struct s_ft_list_node	*next;
	struct s_ft_list_node	*prev;
	void					*item;
}	t_ft_list_node;

typedef struct s_ft_list
{
	struct s_ft_list_node	*first;
	struct s_ft_list_node	*last;
	int						len;
}	t_ft_list;

t_ft_list		*ft_list_new(void);
void			ft_list_free(t_ft_list *list);
void			ft_list_free_all(t_ft_list	*list, void (*del)(void *));

t_ft_list_node	*_ft_list_node_at(t_ft_list *list, int index);
t_ft_list_node	*_ft_list_find_node_w_item(t_ft_list *list, void *item);
t_ft_list_node	*_ft_list_find_node_w_item_back(t_ft_list *list, void *item);
int				_ft_list_true_index(t_ft_list *list, int index);

void			ft_list_add_front(t_ft_list *list, void *item);
void			ft_list_add_back(t_ft_list *list, void *item);
void			ft_list_insert(t_ft_list *list, int index, void *item);

void			*ft_list_pop_front(t_ft_list *list);
void			*ft_list_pop_back(t_ft_list *list);
BOOL			ft_list_remove(t_ft_list *list, void *item);
BOOL			ft_list_remove_back(t_ft_list *list, void *item);
void			*ft_list_remove_at(t_ft_list *list, int index);

void			*ft_list_item_at(t_ft_list *list, int index);
int				ft_list_find_index(t_ft_list *list, void *item);
void			*ft_list_replace_at(t_ft_list *list, int index, void *item);
t_ft_list		*ft_list_reverse(t_ft_list *list);
t_ft_list		*ft_list_reverse_new(t_ft_list *list);

t_ft_list		*ft_list_new_from_array(void **array);
t_ft_list		*ft_list_new_from_array_n(void **array, int lenght);
void			**ft_list_to_array(t_ft_list *list);

UINT			_ft_list_print_s(int fd, t_ft_list *list);
UINT			_ft_list_print_m(int fd, t_ft_list *list);
UINT			_ft_list_print_i(int fd, t_ft_list *list);
UINT			_ft_list_print_u(int fd, t_ft_list *list);

#endif
