/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   skip_space.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 09:36:53 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/03/02 09:43:34 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*skip_space(char *src)
{
	while (*src == ' ')
		src++;
	return (src);
}