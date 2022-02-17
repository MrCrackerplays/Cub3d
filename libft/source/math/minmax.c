/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minmax.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 17:42:48 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/01/28 15:34:15 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_int_limits.h>

LLONG	ft_math_max(LLONG n1, LLONG n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

ULLONG	ft_math_max_u(ULLONG n1, ULLONG n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

LLONG	ft_math_min(LLONG n1, LLONG n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

ULLONG	ft_math_min_u(ULLONG n1, ULLONG n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}
