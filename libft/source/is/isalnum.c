/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isalnum.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 14:02:20 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/22 14:02:51 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_is.h>

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
