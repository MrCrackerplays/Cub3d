/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   abs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 14:20:46 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/01/25 13:31:04 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_int_limits.h>

LLONG	ft_math_abs(LLONG n)
{
	return ((n + (n >> g_llong_size)) ^ (n >> g_llong_size));
}
