/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strstr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:30:39 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/23 15:59:41 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cstring.h>

char	*ft_strstr(char *big, char *little)
{
	size_t	bi;
	size_t	li;

	if (big == little || ft_strlen(little) == 0)
		return ((char *) big);
	bi = 0;
	while (big[bi])
	{
		if (big[bi] == little[0])
		{
			li = 0;
			while (little[li] && big[bi + li] == little[li])
			{
				li++;
				if (!little[li])
					return ((char *) big + bi);
			}
		}
		bi++;
	}
	return (NULL);
}

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	bi;
	size_t	li;

	if (big == little || ft_strlen(little) == 0)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	bi = 0;
	while (big[bi] && bi < len)
	{
		if (big[bi] == little[0])
		{
			li = 0;
			while (big[bi + li] == little[li])
			{
				li++;
				if (!little[li])
					return ((char *) big + bi);
				if (bi + li >= len)
					return (NULL);
			}
		}
		bi++;
	}
	return (NULL);
}
