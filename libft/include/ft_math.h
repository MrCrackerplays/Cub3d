/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_math.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 14:21:34 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/08 19:29:19 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <ft_int_types.h>

LLONG	ft_math_abs(LLONG n);

LLONG	ft_math_max(LLONG n1, LLONG n2);
ULLONG	ft_math_max_u(ULLONG n1, ULLONG n2);
LLONG	ft_math_min(LLONG n1, LLONG n2);
ULLONG	ft_math_min_u(ULLONG n1, ULLONG n2);

int		ft_true_index(UINT size, int index);

#endif
