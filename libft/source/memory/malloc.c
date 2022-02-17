/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:33:14 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/06 16:20:07 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_malloc(size_t size)
{
	void	*item;

	item = malloc(size);
	if (!item)
	{
		perror(NULL);
		exit(1);
	}
	return (item);
}

void	*ft_malloc_e(size_t size, char *error)
{
	void	*item;

	item = malloc(size);
	if (!item)
	{
		perror(error);
		exit(1);
	}
	return (item);
}
