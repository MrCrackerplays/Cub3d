/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_limits.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 17:32:54 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/01/25 12:33:14 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_LIMITS_H
# define FT_INT_LIMITS_H

# include <ft_int_types.h>

extern const BYTE		g_sbyte_size;
extern const SBYTE		g_sbyte_min;
extern const SBYTE		g_sbyte_max;
extern const BYTE		g_byte_size;
extern const BYTE		g_byte_max;

extern const BYTE		g_short_size;
extern const short		g_short_min;
extern const short		g_short_max;
extern const BYTE		g_ushort_size;
extern const USHORT		g_ushort_max;

extern const BYTE		g_int_size;
extern const int		g_int_min;
extern const int		g_int_max;
extern const BYTE		g_uint_size;
extern const UINT		g_uint_max;

extern const BYTE		g_long_size;
extern const long		g_long_min;
extern const long		g_long_max;
extern const BYTE		g_ulong_size;
extern const ULONG		g_ulong_max;

extern const BYTE		g_llong_size;
extern const LLONG		g_llong_min;
extern const LLONG		g_llong_max;
extern const BYTE		g_ullong_size;
extern const ULLONG		g_ullong_max;

#endif
