/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcpy.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 18:33:19 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/11 12:40:57 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_exit_error.h>

char	*ft_strcpy(char *des, char *src)
{
	int	index;

	if (!des || !src)
		ft_exit_error_d("libft: ft_strcpy: got a NULL cstring");
	index = 0;
	while (src[index])
	{
		des[index] = src[index];
		index++;
	}
	des[index] = '\0';
	return (des);
}

char	*ft_strncpy(char *des, const char *src, size_t n)
{
	size_t	i;

	if (!des || !src)
		ft_exit_error_d("libft: ft_strncpy: got a NULL cstring");
	i = 0;
	while (i < n && src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}
	des[n] = '\0';
	return (des);
}
