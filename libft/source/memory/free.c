/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 15:50:13 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 15:50:13 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free(void *i1)
{
	if (i1)
		free(i1);
}

void	ft_free2(void *i1, void *i2)
{
	if (i1)
		free(i1);
	if (i2)
		free(i2);
}

void	ft_free3(void *i1, void *i2, void *i3)
{
	if (i1)
		free(i1);
	if (i2)
		free(i2);
	if (i3)
		free(i3);
}

void	ft_free4(void *i1, void *i2, void *i3, void *i4)
{
	if (i1)
		free(i1);
	if (i2)
		free(i2);
	if (i3)
		free(i3);
	if (i4)
		free(i4);
}
