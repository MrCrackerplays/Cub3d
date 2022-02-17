/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strchr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 18:30:20 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 18:30:53 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(char *src, int c)
{
	char	ch;

	ch = (char) c;
	while (*src)
	{
		if (*src == ch)
			return ((char *) src);
		src++;
	}
	if (!ch)
		return ((char *) src);
	return (NULL);
}
