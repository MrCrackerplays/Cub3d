/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 15:50:05 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 15:50:05 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stddef.h>

void	*ft_malloc(size_t size);
void	*ft_malloc_e(size_t size, char *error);

void	ft_free(void *i1);
void	ft_free2(void *i1, void *i2);
void	ft_free3(void *i1, void *i2, void *i3);
void	ft_free4(void *i1, void *i2, void *i3, void *i4);

void	ft_free_n(void **i1);
void	ft_free_n2(void **i1, void **i2);
void	ft_free_n3(void **i1, void **i2, void **i3);
void	ft_free_n4(void **i1, void **i2, void **i3, void **i4);

#endif
